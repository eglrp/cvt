/*
   The MIT License (MIT)

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
#ifndef CL_PROXPRECONDCL_H
#define CL_PROXPRECONDCL_H

#include <cvt/gfx/Image.h>
#include <cvt/cl/CLKernel.h>
#include <cvt/math/Vector.h>

namespace cvt {
    class ProxPrecondCL {
        public:
            ProxPrecondCL();
            ~ProxPrecondCL();

            void precondEdgeClampSeparable3( Image& output, const Vector3f& kx, const Vector3f& ky );
            void precondEdgeZeroSeparable3( Image& output, const Vector3f& kx, const Vector3f& ky );

        private:
            CLKernel _clprecond_edgeclamp_sep3;
            CLKernel _clprecond_edgezero_sep3;
    };
}
#endif
