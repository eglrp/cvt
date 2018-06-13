/*
   The MIT License (MIT)

   Copyright (c) 2011 - 2013, Philipp Heise and Sebastian Klose
   Copyright (c) 2016, BMW Car IT GmbH, Philipp Heise (philipp.heise@bmw.de)

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

const sampler_t SAMPLER_CLAMP_NN = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_CLAMP_TO_EDGE | CLK_FILTER_NEAREST;
const sampler_t SAMPLER_NN = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_CLAMP | CLK_FILTER_NEAREST;

__kernel void PDMSC( __write_only image2d_t out, __write_only image2d_t outp, __read_only image2d_t last, __read_only image2d_t imgp, __read_only image2d_t image,
                    const float lambda, const float sigma, const float tau, const float theta, __local float4* buf, __local float8* buf2  )
{
    const int gx = get_global_id( 0 );
    const int gy = get_global_id( 1 );
    const int lx = get_local_id( 0 );
    const int ly = get_local_id( 1 );
    const int lw = get_local_size( 0 );
    const int lh = get_local_size( 1 );
    const int bstride = lw + 2;
    const int2 base = ( int2 )( get_group_id( 0 ) * lw - 1, get_group_id( 1 ) * lh - 1 );
    const int2 base2 = ( int2 )( get_group_id( 0 ) * ( lw << 1 ) - 2, get_group_id( 1 ) * lh - 1 );
    int2 coord;
    float4 dx, dy, div, pxout, pyout, norm;

    for( int y = ly; y < lh + 2; y += lh ) {
        for( int x = lx; x < lw + 2; x += lw ) {
            // read image
            buf[ mad24( y, bstride, x ) ] = read_imagef( last, SAMPLER_CLAMP_NN, base + ( int2 ) ( x, y ) );
        }
    }

    barrier( CLK_LOCAL_MEM_FENCE );

#define BUF( x, y ) ( buf[ mad24( ( y ) , bstride, ( x )  ) ] )

#define BUF2( x, y ) ( buf2[ mad24( ( y ) + 1 , bstride, ( x ) + 1  ) ] )

    for( int y = ly; y < lh + 1; y += lh ) {
        coord.y = base2.y + y;
        for( int x = lx; x < lw + 1; x += lw ) {

            dx = BUF( x, y ) - BUF( x + 1, y );
            dy = BUF( x, y ) - BUF( x, y + 1 );

            // p = p + sigma * \nabla last
            float8 p;
            coord.x = base2.x + ( x << 1 );
            p.lo = read_imagef( imgp, SAMPLER_NN, coord ) + sigma * dx;
            coord.x += 1;
            p.hi = read_imagef( imgp, SAMPLER_NN, coord ) + sigma * dy;

            // Moreau identity for solving the prox operator
            if( ( dot( p.lo, p.lo ) + dot( p.hi, p.hi ) ) > 2.0f * lambda * sigma )
                p = ( float8 ) 0.0f;

            buf2[ mad24( y, bstride, x ) ] = p;
        }
    }

    barrier( CLK_LOCAL_MEM_FENCE );

    if( gx >= get_image_width( image ) || gy >= get_image_height( image ) )
        return;


    float8 p = BUF2( lx, ly );
    div = p.lo - BUF2( lx - 1, ly ).lo + p.hi - BUF2( lx, ly - 1 ).hi;

    float4 img    = read_imagef( image, SAMPLER_NN, ( int2 )( gx, gy ) );
    float4 imgnew = ( BUF( lx + 1, ly + 1 ) + tau * ( 2.0f * img - div ) ) / ( float4 ) ( 1.0f + 2.0f * tau );
    imgnew += theta * ( imgnew - BUF( lx + 1, ly + 1 )  );

    write_imagef( out, ( int2 ) ( gx, gy ), imgnew  );
    write_imagef( outp, ( int2 ) ( gx << 1, gy ), p.lo );
    write_imagef( outp, ( int2 ) ( ( gx << 1 ) + 1, gy ), p.hi );
}

__kernel void PDMSC_CWISE( __write_only image2d_t out, __write_only image2d_t outp, __read_only image2d_t last, __read_only image2d_t imgp, __read_only image2d_t image,
                    const float lambda, const float sigma, const float tau, const float theta, __local float4* buf, __local float8* buf2  )
{
    const int gx = get_global_id( 0 );
    const int gy = get_global_id( 1 );
    const int lx = get_local_id( 0 );
    const int ly = get_local_id( 1 );
    const int lw = get_local_size( 0 );
    const int lh = get_local_size( 1 );
    const int bstride = lw + 2;
    const int2 base = ( int2 )( get_group_id( 0 ) * lw - 1, get_group_id( 1 ) * lh - 1 );
    const int2 base2 = ( int2 )( get_group_id( 0 ) * ( lw << 1 ) - 2, get_group_id( 1 ) * lh - 1 );
    int2 coord;
    float4 dx, dy, div, pxout, pyout, norm;

    for( int y = ly; y < lh + 2; y += lh ) {
        for( int x = lx; x < lw + 2; x += lw ) {
            // read image
            buf[ mad24( y, bstride, x ) ] = read_imagef( last, SAMPLER_CLAMP_NN, base + ( int2 ) ( x, y ) );
        }
    }

    barrier( CLK_LOCAL_MEM_FENCE );

#define BUF( x, y ) ( buf[ mad24( ( y ) , bstride, ( x )  ) ] )

#define BUF2( x, y ) ( buf2[ mad24( ( y ) + 1 , bstride, ( x ) + 1  ) ] )

    for( int y = ly; y < lh + 1; y += lh ) {
        coord.y = base2.y + y;
        for( int x = lx; x < lw + 1; x += lw ) {

            dx = BUF( x, y ) - BUF( x + 1, y );
            dy = BUF( x, y ) - BUF( x, y + 1 );

            // p = p + sigma * \nabla last
            float8 p;
            coord.x = base2.x + ( x << 1 );
            p.lo = read_imagef( imgp, SAMPLER_NN, coord ) + sigma * dx;
            coord.x += 1;
            p.hi = read_imagef( imgp, SAMPLER_NN, coord ) + sigma * dy;

            // Moreau identity for solving the prox operator
            float4 plen = p.lo * p.lo + p.hi * p.hi;

            int4 mask = isgreater( plen, 2.0f * lambda * sigma );
            p = select( p, 0.0f, ( int8 ) ( mask, mask ) );

            buf2[ mad24( y, bstride, x ) ] = p;
        }
    }

    barrier( CLK_LOCAL_MEM_FENCE );

    if( gx >= get_image_width( image ) || gy >= get_image_height( image ) )
        return;

    float8 p = BUF2( lx, ly );
    div = p.lo - BUF2( lx - 1, ly ).lo + p.hi - BUF2( lx, ly - 1 ).hi;

    float4 img    = read_imagef( image, SAMPLER_NN, ( int2 )( gx, gy ) );
    float4 imgnew = ( BUF( lx + 1, ly + 1 ) + tau * ( 2.0f * img - div ) ) / ( float4 ) ( 1.0f + 2.0f * tau );
    imgnew += theta * ( imgnew - BUF( lx + 1, ly + 1 )  );

    write_imagef( out, ( int2 ) ( gx, gy ), imgnew  );
    write_imagef( outp, ( int2 ) ( gx << 1, gy ), p.lo );
    write_imagef( outp, ( int2 ) ( ( gx << 1 ) + 1, gy ), p.hi );
}
