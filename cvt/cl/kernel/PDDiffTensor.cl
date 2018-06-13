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

__kernel void PDDiffTensorColor( __write_only image2d_t out, __read_only image2d_t src, const float alpha, const float beta  )
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
    local float buf[ 18 ][ 18 ];
    const float4 grayWeight =  ( float4 ) ( 0.2126f, 0.7152f, 0.0722f, 0.0f );

    for( int y = ly; y < lh + 2; y += lh ) {
        for( int x = lx; x < lw + 2; x += lw ) {
            buf[ y ][ x ] = dot( read_imagef( src, sampler, base + ( int2 )( x, y ) ), grayWeight );
        }
    }
    barrier( CLK_LOCAL_MEM_FENCE );

#define BUF( x, y ) buf[ y + 1 ][ x + 1 ]

    if( gx >= width || gy >= height )
        return;

    float dx = ( BUF( lx + 1 , ly ) - BUF( lx, ly ) );
    float dy = ( BUF( lx, ly + 1  ) - BUF( lx, ly ) );

    float4 dt;
    float len = sqrt( dx * dx + dy * dy );
    float w = exp( -alpha * pow( len, beta ) );
    if( len <= 0.001f ) {
        dt = ( float4 ) ( 1.0f, 0.0f, 0.0f, 1.0f );
    } else {
        dx = dx / len;
        dy = dy / len;

        float dxo = dy;
        float dyo = -dx;
        dt.x = w * dx * dx + dxo * dxo;
        dt.y = w * dx * dy + dxo * dyo;
        dt.z = w * dy * dx + dyo * dxo;
        dt.w = w * dy * dy + dyo * dyo;
    }

    write_imagef( out,( int2 )( gx, gy ), ( float4 ) ( dt ) );
}

__kernel void PDDiffTensorGray( __write_only image2d_t out, __read_only image2d_t src, const float alpha, const float beta  )
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
    local float buf[ 18 ][ 18 ];

    for( int y = ly; y < lh + 2; y += lh ) {
        for( int x = lx; x < lw + 2; x += lw ) {
            buf[ y ][ x ] = read_imagef( src, sampler, base + ( int2 )( x, y ) ).x;
        }
    }
    barrier( CLK_LOCAL_MEM_FENCE );

#define BUF( x, y ) buf[ y + 1 ][ x + 1 ]

    if( gx >= width || gy >= height )
        return;

    float dx = ( BUF( lx + 1 , ly ) - BUF( lx, ly ) );
    float dy = ( BUF( lx, ly + 1  ) - BUF( lx, ly ) );

    float4 dt;
    float len = sqrt( dx * dx + dy * dy );
    float w = exp( -alpha * pow( len, beta ) );
    if( len <= 0.001f ) {
        dt = ( float4 ) ( 1.0f, 0.0f, 0.0f, 1.0f );
    } else {
        dx = dx / len;
        dy = dy / len;

        float dxo = dy;
        float dyo = -dx;
        dt.x = w * dx * dx + dxo * dxo;
        dt.y = w * dx * dy + dxo * dyo;
        dt.z = w * dy * dx + dyo * dxo;
        dt.w = w * dy * dy + dyo * dyo;
    }

    write_imagef( out,( int2 )( gx, gy ), ( float4 ) ( dt ) );
}

__kernel void PDDiffTensorConfidenceColor( __write_only image2d_t out, __read_only image2d_t src, __read_only image2d_t cimg, const float alpha, const float beta  )
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
    local float buf[ 18 ][ 18 ];
    const float4 grayWeight =  ( float4 ) ( 0.2126f, 0.7152f, 0.0722f, 0.0f );

    for( int y = ly; y < lh + 2; y += lh ) {
        for( int x = lx; x < lw + 2; x += lw ) {
            buf[ y ][ x ] = dot( read_imagef( src, sampler, base + ( int2 )( x, y ) ), grayWeight );
        }
    }
    barrier( CLK_LOCAL_MEM_FENCE );

#define BUF( x, y ) buf[ y + 1 ][ x + 1 ]

    if( gx >= width || gy >= height )
        return;

    float dx = ( BUF( lx + 1 , ly ) - BUF( lx, ly ) );
    float dy = ( BUF( lx, ly + 1  ) - BUF( lx, ly ) );

    float4 dt;
    float confid = read_imagef( cimg, sampler, ( int2 )( gx, gy ) ).x;

    float len = sqrt(  dx * dx + dy * dy );
    if( len <= 0.001f ) {
        dt = ( float4 ) ( 1.0f, 0.0f, 0.0f, 1.0f );
    } else {
        dx = dx / len;
        dy = dy / len;

        float dxo = dy;
        float dyo = -dx;

        float w = exp( -alpha * pow( len, beta ) );

        dt.x = w * dx * dx + dxo * dxo;
        dt.y = w * dx * dy + dxo * dyo;
        dt.z = w * dy * dx + dyo * dxo;
        dt.w = w * dy * dy + dyo * dyo;
    }

   // dt = ( 1.0f - confid ) * dt;
//    dt = dt / ( 1.0f + confid * 2.0f );

    write_imagef( out,( int2 )( gx, gy ), ( float4 ) ( dt ) );
}

__kernel void PDDiffTensorConfidenceGray( __write_only image2d_t out, __read_only image2d_t src, __read_only image2d_t cimg, const float alpha, const float beta  )
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
    local float buf[ 18 ][ 18 ];

    for( int y = ly; y < lh + 2; y += lh ) {
        for( int x = lx; x < lw + 2; x += lw ) {
            buf[ y ][ x ] = read_imagef( src, sampler, base + ( int2 )( x, y ) ).x;
        }
    }
    barrier( CLK_LOCAL_MEM_FENCE );

#define BUF( x, y ) buf[ y + 1 ][ x + 1 ]

    if( gx >= width || gy >= height )
        return;

    float dx = ( BUF( lx + 1 , ly ) - BUF( lx, ly ) );
    float dy = ( BUF( lx, ly + 1  ) - BUF( lx, ly ) );
    float confid = read_imagef( cimg, sampler, ( int2 )( gx, gy ) ).x;

    float len = sqrt( dx * dx + dy * dy );
    float w = exp( -alpha * pow( len, beta ) );
    if( len <= 0.0001f ) {
        dx = 1.0f;
        dy = 0.0f;
    } else {
        dx = dx / len;
        dy = dy / len;
    }

    float4 dt;
    float dxo = dy;
    float dyo = -dx;
    dt.x = w * dx * dx + dxo * dxo;
    dt.y = w * dx * dy + dxo * dyo;
    dt.z = w * dy * dx + dyo * dxo;
    dt.w = w * dy * dy + dyo * dyo;

    dt = dt / ( 1.0f + confid * 1.0f );

    write_imagef( out,( int2 )( gx, gy ), ( float4 ) ( dt ) );
}
