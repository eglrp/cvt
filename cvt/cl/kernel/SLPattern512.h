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
#ifndef CVT_SLPATTERN512_H
#define CVT_SLPATTERN512_H

__constant const int _brief_pattern[][ 4 ] = {
    { -6, -7, -4, 6 },
    { 4, 0, -3, -4 },
    { -11, 15, -18, -39 },
    { 3, -4, -2, 1 },
    { 8, 4, 29, 35 },
    { 18, -13, 19, 2 },
    { 24, -36, 15, -33 },
    { 0, 0, -3, -3 },
    { 7, 2, 2, 1 },
    { 1, 3, 2, -5 },
    { 4, -36, -23, -20 },
    { -6, 6, 1, 6 },
    { -5, 4, -6, 6 },
    { 9, 6, 8, -2 },
    { 18, 8, -15, 5 },
    { -4, 5, -9, -2 },
    { 9, -3, 6, 4 },
    { -39, 11, -38, -6 },
    { 3, -8, -4, 5 },
    { -20, 31, 18, -14 },
    { 6, -1, 6, 4 },
    { -6, 2, 8, -6 },
    { -4, -12, -7, 22 },
    { 3, 3, -5, -6 },
    { -21, 28, -38, 19 },
    { 0, -3, 6, -3 },
    { -3, 10, -8, -2 },
    { -14, -18, -19, 35 },
    { 9, 2, 2, -1 },
    { -4, -3, -3, 5 },
    { 4, 3, -5, -5 },
    { -5, -5, 5, -3 },
    { 7, 5, 4, 6 },
    { -3, 3, -6, 5 },
    { -8, 39, -16, -28 },
    { -1, 0, -6, -1 },
    { -6, 6, -6, -1 },
    { 3, 5, -7, -5 },
    { 4, 2, 10, 8 },
    { -3, -34, -6, 25 },
    { 0, -3, 6, -1 },
    { -2, 4, 2, 2 },
    { -35, 15, 16, 16 },
    { -3, 0, 6, -5 },
    { 5, -2, -5, -1 },
    { 26, -14, -3, 26 },
    { -7, 4, -1, -6 },
    { -3, -5, -7, 1 },
    { -6, 6, -3, 3 },
    { -31, 8, 37, -13 },
    { -2, -6, 7, -4 },
    { -2, -9, -10, -3 },
    { 21, 39, 35, -15 },
    { -38, 33, 7, -16 },
    { 6, 6, 4, 7 },
    { 1, 0, 4, 0 },
    { 1, 8, 19, -18 },
    { 10, -3, -5, 3 },
    { -2, 4, 9, -8 },
    { 7, -2, -2, -5 },
    { -13, -5, 2, 28 },
    { -5, -5, 7, 5 },
    { -7, 5, -6, -1 },
    { -5, -4, -2, 1 },
    { -1, -7, -6, 0 },
    { -4, 5, -3, 5 },
    { -4, -6, -1, -6 },
    { 0, -1, -1, 6 },
    { 6, 6, -7, -7 },
    { -19, -29, -37, 33 },
    { -5, -3, 4, -3 },
    { 1, 1, -6, -4 },
    { 5, 7, -6, 0 },
    { 4, 8, -5, -4 },
    { 1, -7, -1, 5 },
    { -5, -7, 2, -7 },
    { -5, -8, 2, -4 },
    { -2, -3, 2, 2 },
    { -10, -8, -4, -3 },
    { -5, -2, 1, 5 },
    { 11, 28, 8, 40 },
    { 6, -6, 6, -6 },
    { 6, 4, 0, 4 },
    { 10, -7, -8, 4 },
    { 5, -24, 13, 36 },
    { -22, 39, 35, -7 },
    { -5, 2, 2, 2 },
    { 5, 5, 4, 4 },
    { -3, 9, -6, 1 },
    { 1, -4, 2, 0 },
    { 36, -21, -9, 11 },
    { -3, -6, 6, -2 },
    { 5, -2, -6, 7 },
    { 6, 4, -2, 6 },
    { 5, 6, -3, 2 },
    { -1, -5, -2, -4 },
    { 20, 8, -21, 39 },
    { -1, -7, 6, 1 },
    { 6, 3, -5, 4 },
    { -9, 5, 2, -3 },
    { 4, -40, 16, 11 },
    { -39, 0, -2, -16 },
    { 4, 6, -3, -7 },
    { -4, 4, -2, -5 },
    { 3, -3, 4, -5 },
    { 4, 1, 2, -2 },
    { -1, -7, -7, -7 },
    { -7, -1, -3, 1 },
    { -32, 19, -28, -11 },
    { 5, -2, 6, 10 },
    { -1, 1, 5, 6 },
    { 8, 8, 7, -9 },
    { 1, -5, 8, -5 },
    { -8, 8, -5, 4 },
    { -27, 10, 34, -10 },
    { -4, -1, -2, 8 },
    { 6, -5, 5, -2 },
    { 9, -3, -6, 1 },
    { 3, 4, -4, 3 },
    { 5, 0, -4, 5 },
    { -2, 3, 7, 2 },
    { -2, -8, -2, 7 },
    { 5, -8, 0, -7 },
    { -1, -1, 4, -4 },
    { -15, -16, -34, 11 },
    { -8, -10, 7, -7 },
    { 1, 6, -7, -4 },
    { 1, 3, 3, 3 },
    { 3, -1, 6, 1 },
    { -22, 27, -19, 25 },
    { 1, 4, 1, -5 },
    { -4, 4, -2, 0 },
    { 7, -27, -6, 28 },
    { 2, 2, -3, 4 },
    { 3, -3, 9, 9 },
    { -4, -2, -10, 2 },
    { 6, 6, 1, -5 },
    { -25, 7, 21, -39 },
    { -10, -4, -14, -37 },
    { -4, 1, 6, -6 },
    { -5, 2, -3, 9 },
    { -4, 8, -3, -2 },
    { 5, 3, 0, -1 },
    { -7, -6, 6, -6 },
    { 6, -6, -4, -2 },
    { 0, 5, 6, -10 },
    { -3, -2, 1, 0 },
    { -1, 31, -13, -33 },
    { -4, -2, 3, -3 },
    { -8, -11, 34, -22 },
    { -2, -1, -2, -2 },
    { 0, 0, 3, -5 },
    { 2, 3, 3, -2 },
    { 5, 7, -2, 7 },
    { -9, 8, 2, 4 },
    { -5, 5, 5, 5 },
    { 25, 38, -11, 14 },
    { -1, 7, -2, -10 },
    { -38, -34, -25, -26 },
    { 2, -5, -5, -3 },
    { -18, 10, -37, -7 },
    { -6, -7, -3, 2 },
    { 2, 5, -2, 1 },
    { 7, 1, -3, -2 },
    { -10, -4, 4, -4 },
    { -3, 4, 7, -3 },
    { -3, -9, -5, -3 },
    { -2, 1, 0, 0 },
    { -6, 6, 4, -4 },
    { -6, -6, 0, -4 },
    { -21, 35, 25, -6 },
    { -5, -10, -1, 4 },
    { 2, 7, 1, -4 },
    { 14, 11, -29, 7 },
    { -4, 0, -4, 7 },
    { 21, -19, 7, 18 },
    { 3, 2, -5, -1 },
    { 3, 6, 1, 5 },
    { 15, 5, -16, 30 },
    { -1, 3, 4, 0 },
    { 29, 36, -30, -40 },
    { 24, -15, 7, -10 },
    { 1, -5, 2, -2 },
    { -6, 1, 2, 5 },
    { 6, 0, 4, 7 },
    { 8, -9, -2, 5 },
    { 3, 1, -4, 1 },
    { 3, -4, -4, 0 },
    { 2, -6, -1, -2 },
    { -7, -34, 13, 29 },
    { -9, -7, 2, -3 },
    { -9, -36, -38, -27 },
    { 37, 39, 27, 22 },
    { -5, 5, 8, -3 },
    { 7, 7, 2, -7 },
    { 2, -6, -2, 7 },
    { 7, 0, -6, -5 },
    { -3, -4, 2, 9 },
    { -5, -5, 5, 6 },
    { -4, 5, -2, 3 },
    { 0, 0, -6, 5 },
    { 7, 5, -1, -1 },
    { 35, 0, -38, 21 },
    { 3, 24, -5, -31 },
    { 0, 2, -6, 6 },
    { -36, 29, 40, 19 },
    { 28, -14, 8, 15 },
    { -8, -5, -10, -5 },
    { -1, 3, 2, -6 },
    { -33, -37, -20, -19 },
    { -4, 7, 7, 3 },
    { -3, -4, 4, 6 },
    { -37, 9, -21, 9 },
    { 15, 11, 25, 7 },
    { -7, 2, -3, -4 },
    { 7, 7, 1, 4 },
    { 3, 7, -1, 6 },
    { -4, 3, -8, -7 },
    { -3, 4, -3, 1 },
    { 4, 5, 5, 5 },
    { -5, -5, 4, -5 },
    { -2, -7, -2, -1 },
    { 28, 35, -5, -4 },
    { 6, -5, -4, -6 },
    { -3, -6, 1, 2 },
    { 4, 2, 4, 4 },
    { 3, -4, 6, -5 },
    { 37, -3, 9, -24 },
    { 2, -1, 3, 2 },
    { 27, -36, 1, 40 },
    { 4, -5, 1, -5 },
    { 1, -2, 1, 6 },
    { -6, -6, -5, 3 },
    { -11, 24, 29, -6 },
    { 4, -5, -4, 1 },
    { 2, -3, 4, -6 },
    { 5, -1, -7, 3 },
    { -23, -2, 15, -23 },
    { -16, -17, 8, -32 },
    { 9, -9, 5, 6 },
    { -7, 4, 10, 8 },
    { -7, -8, -2, -7 },
    { 27, 22, -23, -24 },
    { -8, 0, -6, 7 },
    { 6, -1, -36, -17 },
    { 5, -3, -3, 0 },
    { -3, -2, -6, 7 },
    { 7, -3, -7, -9 },
    { -5, -3, 9, 6 },
    { -15, -21, -18, -38 },
    { -5, -7, -6, 7 },
    { 1, 3, -6, -6 },
    { 1, -1, 1, -1 },
    { -3, -1, -3, 0 },
    { -38, -17, 35, -9 },
    { -17, 8, -2, -17 },
    { 27, 13, -28, -34 },
    { 20, 6, 37, 24 },
    { -27, 8, 25, 32 },
    { 3, 5, 0, 3 },
    { 5, 1, 3, -1 },
    { 2, 5, 0, 0 },
    { 6, -7, 1, -3 },
    { -1, -3, -2, 8 },
    { -14, -34, 16, 5 },
    { 2, -1, -3, -1 },
    { -3, 0, 0, 7 },
    { -9, -4, -10, -5 },
    { 21, 5, 30, 36 },
    { 1, -6, -2, 5 },
    { -24, -14, 19, -37 },
    { -1, 3, -5, -5 },
    { -34, 5, 14, -4 },
    { 1, 5, 4, -3 },
    { -4, 9, 2, 4 },
    { 17, -29, -34, 25 },
    { -7, -2, -6, -5 },
    { -1, -7, -2, 7 },
    { 7, 0, 6, 4 },
    { 2, 6, -6, 6 },
    { 24, -17, -28, -23 },
    { -6, 2, 0, 5 },
    { 3, 4, -6, 5 },
    { 0, 7, 0, 3 },
    { 35, -29, 37, 10 },
    { -4, 9, 0, 3 },
    { -7, 7, -2, 3 },
    { -20, 16, -18, 27 },
    { 4, 5, -1, 0 },
    { 9, 2, 3, 4 },
    { -2, -10, 3, -5 },
    { 2, 0, -4, 1 },
    { 3, 10, -8, -5 },
    { 0, -7, -5, 0 },
    { -39, 1, -29, 27 },
    { -6, -3, 4, 5 },
    { -9, 4, -3, 3 },
    { 0, -4, -4, -2 },
    { 4, 38, -12, 18 },
    { 18, 28, 5, 12 },
    { -6, 7, 4, -4 },
    { 6, 4, 3, 3 },
    { -1, 0, 0, 5 },
    { -9, 1, 7, 0 },
    { 3, 3, -3, 1 },
    { 10, -10, -7, -8 },
    { -1, -7, -3, -2 },
    { -14, 27, 2, 14 },
    { -5, 1, 2, -1 },
    { -10, 7, 1, -7 },
    { 7, -5, -4, -5 },
    { -7, 1, 6, -1 },
    { -2, -5, 2, -5 },
    { 5, 4, 4, 4 },
    { -8, 7, 7, -1 },
    { 4, 0, -9, -2 },
    { -8, 7, -5, -4 },
    { -11, 32, 5, 39 },
    { -1, 7, 7, 1 },
    { 2, -3, -4, 0 },
    { -3, 5, 3, 6 },
    { -17, 16, -30, 33 },
    { 1, 1, -3, -7 },
    { -3, 1, 2, 0 },
    { -10, 3, -6, 7 },
    { 8, -3, 3, -3 },
    { 6, -1, 4, 5 },
    { 3, -6, -7, 4 },
    { 4, 1, 0, -2 },
    { -10, -2, 2, 9 },
    { -5, -6, 6, -5 },
    { -9, -21, -40, -26 },
    { 3, 0, -2, 10 },
    { -8, 2, 1, -7 },
    { 3, 1, 10, -2 },
    { -3, -6, 2, -4 },
    { 8, -6, -1, 2 },
    { 0, 3, 0, 2 },
    { -4, -5, 7, 1 },
    { 3, 9, 9, -8 },
    { 1, 7, -22, -1 },
    { -38, -1, 16, 26 },
    { 1, 1, 5, -4 },
    { 0, -1, 1, 3 },
    { 2, 7, -1, -1 },
    { 3, 3, 3, 7 },
    { -6, -9, 7, 10 },
    { -3, 9, 2, -8 },
    { 4, -7, -1, 2 },
    { 6, -4, -1, 3 },
    { 11, -37, -20, -8 },
    { 7, -4, -6, 1 },
    { 3, 3, 3, -7 },
    { -36, -19, -25, 21 },
    { 3, -6, 6, -3 },
    { -5, -19, -14, 22 },
    { -6, -2, 3, 1 },
    { 3, -10, 3, -6 },
    { 5, 1, -8, -8 },
    { 0, 5, 7, -9 },
    { 3, 0, 2, 0 },
    { 1, -12, 5, -24 },
    { 0, -6, -1, 0 },
    { 12, 5, 1, 17 },
    { 1, 7, -1, -6 },
    { -2, -4, -3, -2 },
    { -17, -30, 34, -18 },
    { 1, -7, 6, -5 },
    { 0, 6, 0, -10 },
    { 8, -9, 0, 8 },
    { 6, -3, 5, -6 },
    { 5, -1, -6, -5 },
    { -3, -6, -2, -5 },
    { -3, -6, -2, -5 },
    { -24, -8, -15, -24 },
    { -2, 4, -1, -5 },
    { -8, -7, -6, -2 },
    { -6, 3, 6, 1 },
    { 0, 6, -2, 4 },
    { 6, 4, 29, -17 },
    { 1, 1, -4, -3 },
    { 4, -6, -6, -3 },
    { 2, 2, -6, -7 },
    { 6, 2, -4, 1 },
    { 7, -6, 3, -6 },
    { 30, -11, -16, 26 },
    { -7, -3, -3, -6 },
    { 7, -20, 11, -35 },
    { 0, 2, 3, -1 },
    { -6, 6, 2, 6 },
    { 6, -2, 2, 0 },
    { -3, -3, 4, -4 },
    { -3, 4, -3, 4 },
    { 1, 5, 6, -3 },
    { -3, -5, 5, 5 },
    { 17, 12, 1, -19 },
    { 6, -1, 8, -7 },
    { 2, 6, 3, -6 },
    { 1, 3, -3, -6 },
    { -5, -1, 4, 2 },
    { -16, 36, -37, 0 },
    { 8, 6, -3, 0 },
    { 6, -5, 2, 2 },
    { 2, -2, 0, -1 },
    { 9, 6, 6, 0 },
    { 7, 4, -1, 5 },
    { -4, 2, 2, 4 },
    { 31, 11, 14, -15 },
    { -5, 7, -5, -6 },
    { 3, 7, -4, -27 },
    { 5, -1, 0, -5 },
    { -3, 1, -2, -2 },
    { -5, -5, -6, -5 },
    { 8, 1, -8, -7 },
    { 5, -3, 1, 3 },
    { -5, 8, 23, 21 },
    { 9, 8, -2, 1 },
    { 5, 0, 4, 4 },
    { -4, 4, -3, 4 },
    { 2, 6, -2, 2 },
    { 4, 6, 1, -8 },
    { -9, -8, -6, -5 },
    { 8, 4, -1, 4 },
    { 4, 0, 6, -6 },
    { -7, 2, -4, 0 },
    { 6, 5, 7, -2 },
    { -19, -4, -26, -35 },
    { -4, -4, -6, -6 },
    { 18, -9, 23, 33 },
    { 4, 6, 6, 4 },
    { 2, -6, 2, -5 },
    { -5, 1, 2, -2 },
    { -37, 27, 30, -35 },
    { 38, 29, -29, -13 },
    { -2, -1, 0, 5 },
    { 4, -6, -3, 4 },
    { -29, 15, -37, -36 },
    { 5, -2, -6, 4 },
    { 29, 27, 16, 25 },
    { 8, -7, 7, 0 },
    { 1, 5, 3, 6 },
    { 0, -2, 1, -5 },
    { 37, -29, 26, -3 },
    { -37, 16, -39, -22 },
    { -1, -2, -13, -8 },
    { -6, -2, 3, 4 },
    { 2, 5, -7, -4 },
    { -4, -25, 2, -27 },
    { -1, -8, 8, 6 },
    { 3, -6, -3, -1 },
    { 2, 2, 0, -4 },
    { -3, -3, 5, 3 },
    { 4, 4, 6, 6 },
    { -27, -23, 37, 13 },
    { 6, -5, -2, 6 },
    { 3, -2, 8, 3 },
    { 4, -4, -6, -2 },
    { -5, -7, 4, -3 },
    { 7, 37, 7, -14 },
    { -4, -5, 5, -3 },
    { 1, -5, -5, 2 },
    { 1, 6, -8, -8 },
    { -1, -4, 3, -5 },
    { 5, -3, 2, 5 },
    { 8, -7, 10, -10 },
    { 3, -1, 0, -4 },
    { 5, 0, -1, -3 },
    { -7, -1, 6, 8 },
    { 6, 3, -2, -1 },
    { 6, 1, -7, -4 },
    { -21, 10, -17, -22 },
    { 4, 3, -2, 4 },
    { 9, 9, 1, -5 },
    { 35, 18, 34, 25 },
    { -31, -1, 34, -17 },
    { 3, 14, 19, -19 },
    { -7, 7, -2, 9 },
    { -5, 3, 6, 1 },
    { -1, -7, 0, 2 },
    { 12, 11, 35, -26 },
    { -6, -3, 2, -1 },
    { 1, -5, -7, -4 },
    { 21, -3, 9, 11 },
    { 17, 33, 37, 14 },
    { 2, 3, 1, 4 },
    { -5, -8, -4, -5 },
    { -9, -24, -9, 12 },
    { -40, -2, -27, -40 },
    { -5, -6, -4, -1 },
    { 4, 10, 9, -2 },
    { 3, -3, 2, -3 },
    { -1, -1, 4, 6 },
    { -9, -7, 7, -2 },
    { -6, -1, 6, -1 },
    { -2, -4, 3, 6 },
    { -10, 38, 2, -15 },
    { 6, 0, -5, 7 },
    { 3, -2, 1, -6 },
    { 1, -5, 7, -7 },
    { 27, 25, 26, 0 },
    { 5, 6, 2, 6 },
    { 1, -7, 25, -8 },
    { -3, 4, 7, 1 },
    { -4, -1, 5, 2 },
    { -6, -2, 1, 4 },
    { -3, 0, 5, 6 },
    { 6, -2, 7, 7 },
    { -1, 3, 1, 1 },
    { -1, 5, -2, 0 },
    { -11, -3, 29, -1 },
    { 7, -19, 3, -18 },
    { -2, 1, 4, 6 },
    { 1, 2, 5, 4 }
};
#endif