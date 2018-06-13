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
#ifndef CVT_CLUTIL_H
#define CVT_CLUTIL_H

#include <alloca.h>
#include <cvt/cl/CLException.h>
#include <cvt/util/String.h>

#define CLUTIL_GETINFOSTRING( name, info, clobj, clobjinfofunc ) \
    void name( String& string ) const\
{   \
    cl_int err; \
    size_t size; \
    err = clobjinfofunc( clobj, info, 0, NULL, &size ); \
    if( err != CL_SUCCESS ) \
        throw CLException( err ); \
    string.resize( size ); \
    err = clobjinfofunc( clobj, info, size, &string[ 0 ], 0 ); \
    string.updateLength(); \
    if( err != CL_SUCCESS ) \
        throw CLException( err ); \
}

#define CLUTIL_GETINFOTYPE( name, info, type, clobj, clobjinfofunc ) \
    type name() const\
{   \
    cl_int err; \
    type ret; \
    err = clobjinfofunc( clobj, info, sizeof( type ), &ret, NULL ); \
    if( err != CL_SUCCESS ) \
        throw CLException( err ); \
    return ret; \
}

#endif
