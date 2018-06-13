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

__kernel void gradxy( __write_only image2d_t out, __read_only image2d_t src, __local float4* buf  )
{
    const sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_CLAMP | CLK_FILTER_NEAREST;
    const int gx = get_global_id( 0 );
    const int gy = get_global_id( 1 );
    const int lx = get_local_id( 0 );
    const int ly = get_local_id( 1 );
    const int lw = get_local_size( 0 );
    const int lh = get_local_size( 1 );
    const int width = get_image_width( out );
    const int height = get_image_height( out );
    const int2 base = ( int2 )( get_group_id( 0 ) * lw - 1, get_group_id( 1 ) * lh - 1 );
    const int bstride = lw + 2;
    float2 coord;
    float4 dx, dy;

    for( int y = ly; y < lh + 2; y += lh ) {
        for( int x = lx; x < lw + 2; x += lw ) {
            buf[ mul24( y, bstride ) + x ] = read_imagef( src, sampler, base + ( int2 )( x, y ) );
        }
    }
    barrier( CLK_LOCAL_MEM_FENCE );

#define BUF( x, y ) buf[ mul24( y + 1 , bstride ) + ( x ) + 1 ]

    if( gx >= width || gy >= height )
        return;

    dx = BUF( lx + 1, ly ) - BUF( lx - 1, ly  );
    dy = BUF( lx, ly + 1 ) - BUF( lx, ly - 1 );
    write_imagef( out,( int2 )( gx, gy ), dx + dy );
#undef BUF
}

__kernel void grad_gray_xydiag( __write_only image2d_t out, __read_only image2d_t src )
{
#define BORDER 1
    const sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_CLAMP | CLK_FILTER_NEAREST;
    const int gx = get_global_id( 0 );
    const int gy = get_global_id( 1 );
    const int lx = get_local_id( 0 );
    const int ly = get_local_id( 1 );
    const int lw = get_local_size( 0 );
    const int lh = get_local_size( 1 );
    const int width = get_image_width( out );
    const int height = get_image_height( out );
    const int bstride = lw + 2;
    const int2 base = ( int2 )( get_group_id( 0 ) * lw - BORDER, get_group_id( 1 ) * lh - BORDER );
    local float buf[ ( 32 + 2 * BORDER ) * ( 32 + 2 * BORDER ) ];
    const float3 grayWeight =  ( float3 ) ( 0.2126f, 0.7152f, 0.0722f );
    float2 coord;
    float dx, dy, dxy, dyx;

    for( int y = ly; y < lh + 2 * BORDER; y += lh ) {
        int yoffset = mul24( y, bstride );
        for( int x = lx; x < lw + 2 * BORDER; x += lw ) {
            buf[ yoffset + x ] = dot( read_imagef( src, sampler, base + ( int2 )( x, y ) ).xyz, grayWeight );
        }
    }
    barrier( CLK_LOCAL_MEM_FENCE );

#define BUF( x, y ) buf[ mul24( y + 1 , bstride ) + ( x ) + 1 ]

    if( gx >= width || gy >= height )
        return;

    dx = BUF( lx + 1, ly ) - BUF( lx - 1, ly  );
    dy = BUF( lx, ly + 1 ) - BUF( lx, ly - 1 );

    dxy = BUF( lx + 1, ly  ) - BUF( lx - 1 , ly  );
    dyx = BUF( lx, ly + 1 ) - BUF( lx , ly - 1 );

    write_imagef( out,( int2 )( gx, gy ), ( float4 ) ( dx, dy, dxy, dyx ) );
#undef BUF
}
