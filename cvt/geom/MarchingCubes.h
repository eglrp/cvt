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

#ifndef CVT_MARCHINGCUBES_H
#define CVT_MARCHINGCUBES_H

#include <cvt/geom/scene/SceneMesh.h>
#include <cvt/math/Vector.h>

namespace cvt {

    class MarchingCubes {
        public:
            MarchingCubes( const float* volume, size_t width, size_t height, size_t depth,
                           bool weighted = false, float minweight = 20.0f, ssize_t channels = -1 );
            ~MarchingCubes();

            void  triangulate( SceneMesh& mesh, float isolevel = 0.0f ) const;
            void  triangulateWithNormals( SceneMesh& mesh, float isolevel = 0.0f, bool EM = false ) const;

            void  setMinimumWeight( float weight );
            float minimumWeight() const;

        private:
            void triangulateDistance( SceneMesh& mesh, float isolevel ) const;
            void triangulateWithNormalsDistance( SceneMesh& mesh, float isolevel ) const;

            void triangulateWeightedDistance( SceneMesh& mesh, float isolevel ) const;
            void triangulateWithNormalsWeightedDistance( SceneMesh& mesh, float isolevel ) const;

            void triangulateWithNormalsEMWeightedDistance( SceneMesh& mesh, float isolevel ) const;

            void vertexInterp( Vector3f& vtx, const Vector3f& p1, const Vector3f& p2, float val1, float val2, float isolevel ) const;
            void vertexNormalInterp( Vector3f& vtx, const Vector3f& p1, const Vector3f& p2, Vector3f& norm, const Vector3f& n1, const Vector3f& n2, float val1, float val2, float isolevel ) const;

            void extractVolumeValues( float* gridvalues, size_t x, size_t y, size_t z ) const;
            bool extractVolumeValuesWithWeightCheck( float* gridvalues, size_t x, size_t y, size_t z, float minWeight ) const;
            void extractVolumeNormals( Vector3f* normal, size_t x, size_t y, size_t z ) const;
            unsigned int cubeIndexFromValues( float* gridvalues, float isolevel ) const;
            void setGridVertices( Vector3f* vtx, size_t x, size_t y, size_t z ) const;
            void interpolateVertices( Vector3f* vertlist, const Vector3f* gridvtx, const float* gridval, unsigned int cubeindex, float isolevel ) const;
            void interpolateVerticesAndNormals( Vector3f* vertlist, Vector3f* normlist, const Vector3f* gridvtx, const Vector3f* gridnormal,
                                                const float* gridval, unsigned int cubeindex, float isolevel ) const;

            const float* _volume;
            size_t       _width;
            size_t       _height;
            size_t       _depth;
            bool         _weighted;
            float        _minweight;
            size_t      _channels;
    };

    inline MarchingCubes::MarchingCubes( const float* volume, size_t width, size_t height, size_t depth, bool weighted, float minweight, ssize_t channels ) :
        _volume( volume ),
        _width( width ),
        _height( height ),
        _depth( depth ),
        _weighted( weighted ),
        _minweight( minweight )
    {
        if( channels < 0 )
            _channels = _weighted ? 2 : 1;
        else
            _channels = channels;
    }

    inline MarchingCubes::~MarchingCubes()
    {
    }

    inline void MarchingCubes::triangulate( SceneMesh& mesh, float isolevel ) const
    {
        if( _weighted )
            triangulateWeightedDistance( mesh, isolevel );
        else
            triangulateDistance( mesh, isolevel );
    }

    inline void MarchingCubes::triangulateWithNormals( SceneMesh& mesh, float isolevel, bool EM ) const
    {
        if( EM ) {
            triangulateWithNormalsEMWeightedDistance( mesh, isolevel );
        } else {
            if( _weighted )
                triangulateWithNormalsWeightedDistance( mesh, isolevel );
            else
                triangulateWithNormalsDistance( mesh, isolevel );
        }
    }

    inline void MarchingCubes::setMinimumWeight( float weight )
    {
        _minweight = weight;
    }

    inline float MarchingCubes::minimumWeight() const
    {
        return _minweight;
    }

    inline void MarchingCubes::vertexInterp( Vector3f& vtx, const Vector3f& p1, const Vector3f& p2, float val1, float val2, float isolevel ) const
    {
        const float ISO_EPSILON = 1e-8f;

        if( Math::abs( isolevel - val1 ) <  ISO_EPSILON ) {
            vtx = p1;
            return;
        }

        if( Math::abs( isolevel - val2 ) <  ISO_EPSILON ) {
            vtx = p2;
            return;
        }

        if( Math::abs( val1 - val2 ) <  ISO_EPSILON ) {
            vtx = p1;
            return;
        }

        float alpha = ( isolevel - val1 ) / ( val2 - val1 );
        vtx.mix( p1, p2, alpha );
    }

    inline void MarchingCubes::vertexNormalInterp( Vector3f& vtx, const Vector3f& p1, const Vector3f& p2,
                                                   Vector3f& norm, const Vector3f& n1, const Vector3f& n2,
                                                   float val1, float val2, float isolevel ) const
    {
        const float ISO_EPSILON = 1e-8f;
        float alpha;

        if( Math::abs( isolevel - val1 ) <  ISO_EPSILON )
            alpha = 0.0f;
        else if( Math::abs( isolevel - val2 ) <  ISO_EPSILON )
            alpha = 1.0f;
        else if( Math::abs( val1 - val2 ) <  ISO_EPSILON )
            alpha = 0.5f;
        else
            alpha = ( isolevel - val1 ) / ( val2 - val1 );
        vtx.mix( p1, p2, alpha );
        norm.mix( n1, n2, alpha );
        norm.normalize();
    }

}

#endif
