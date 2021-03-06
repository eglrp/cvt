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
#ifndef CVT_CENSUS_BRPATTERN_H
#define CVT_CENSUS_BRPATTERN_H

__constant const char _brief_pattern[][ 4 ] = {
    { 8, 18, 20, 46},
    { 0, 0, 7, 29},
    { 1, 2, 1, 4},
    { 19, -6, 48, -15},
    { 3, -3, 5, -3},
    { -1, -5, -1, -3},
    { -2, 1, 0, 1},
    { 0, 0, 2, 0},
    { -20, 0, -50, 1},
    { 15, -14, 36, -34},
    { -7, -19, -17, -47},
    { 3, 1, 3, 3},
    { 3, -4, 3, -2},
    { -3, -20, -8, -49},
    { 18, -8, 46, -20},
    { 4, -20, 9, -49},
    { 2, -4, 4, -4},
    { -5, -4, -3, -4},
    { 3, -2, 3, 0},
    { 2, -2, 2, 0},
    { -3, -1, -3, 1},
    { 0, 0, -30, -2},
    { -2, 2, -2, 4},
    { 0, 0, -16, 25},
    { -19, -7, -47, -16},
    { 0, 2, 0, 4},
    { 3, -1, 3, 1},
    { 4, -5, 4, -3},
    { -4, -2, -2, -2},
    { 0, -4, 2, -4},
    { -3, 4, -1, 4},
    { 0, -2, 0, 0},
    { 15, 13, 38, 33},
    { 2, 0, 4, 0},
    { -4, 3, -2, 3},
    { -19, 7, -46, 18},
    { 0, 0, -22, 20},
    { -2, 20, -6, 50},
    { -17, -10, -44, -25},
    { -3, -4, -1, -4},
    { 0, 0, 21, 22},
    { 2, -1, 2, 1},
    { 0, 0, -28, -10},
    { -8, 18, -19, 46},
    { 1, 0, 1, 2},
    { 0, 1, 0, 3},
    { 2, 2, 2, 4},
    { -3, 1, -1, 1},
    { -4, -1, -4, 1},
    { 0, 0, 24, -19},
    { -2, -2, 0, -2},
    { 3, 2, 3, 4},
    { -2, 0, 0, 0},
    { 1, 2, 3, 2},
    { 0, 3, 0, 5},
    { 3, 0, 5, 0},
    { 3, 3, 5, 3},
    { 2, -3, 2, -1},
    { 2, -4, 2, -2},
    { -13, -15, -32, -38},
    { -5, 3, -3, 3},
    { 0, -20, 1, -50},
    { -1, 3, 1, 3},
    { 1, 3, 3, 3},
    { -15, -13, -39, -32},
    { 16, -12, 39, -31},
    { 1, 3, 1, 5},
    { 12, -16, 30, -40},
    { 2, -2, 4, -2},
    { -1, 1, 1, 1},
    { -2, -1, -2, 1},
    { 1, 1, 1, 3},
    { -3, -1, -1, -1},
    { -1, -3, 1, -3},
    { 6, 19, 16, 47},
    { 2, 1, 2, 3},
    { -5, -3, -3, -3},
    { 19, 5, 48, 13},
    { -3, 3, -3, 5},
    { 20, 4, 49, 9},
    { 1, -4, 3, -4},
    { 20, 2, 50, 4},
    { -10, -17, -25, -43},
    { 0, 0, 29, 8},
    { -3, 3, -1, 3},
    { 1, -2, 3, -2},
    { 1, -5, 1, -3},
    { 10, -17, 26, -43},
    { -5, -1, -3, -1},
    { -3, -3, -1, -3},
    { -4, 1, -2, 1},
    { 1, 4, 3, 4},
    { 9, -18, 22, -45},
    { -3, 2, -1, 2},
    { 4, 2, 4, 4},
    { 20, -4, 49, -11},
    { 10, 18, 24, 44},
    { -2, -20, -4, -50},
    { 2, 1, 4, 1},
    { 0, 0, -9, 29},
    { -4, 4, -2, 4},
    { -1, -1, 1, -1},
    { -1, 3, -1, 5},
    { 17, 10, 43, 25},
    { -5, 4, -3, 4},
    { 0, 1, 2, 1},
    { 1, 20, 3, 50},
    { 20, -1, 50, -2},
    { -2, 3, 0, 3},
    { -3, -3, -3, -1},
    { 0, 0, 30, 0},
    { 3, 2, 5, 2},
    { 18, -9, 44, -24},
    { -2, -4, 0, -4},
    { 0, 0, -13, -27},
    { 3, 4, 5, 4},
    { 0, 2, 2, 2},
    { 5, 19, 12, 49},
    { -19, 6, -48, 14},
    { 3, -3, 3, -1},
    { -4, -5, -4, -3},
    { 16, 12, 41, 29},
    { 0, 0, 3, -30},
    { 1, -3, 3, -3},
    { -12, -16, -29, -41},
    { -17, 11, -42, 26},
    { -9, 18, -23, 44},
    { 3, 3, 3, 5},
    { 2, -5, 2, -3},
    { 2, 0, 2, 2},
    { 2, -20, 5, -50},
    { 13, -15, 33, -37},
    { -18, 9, -45, 23},
    { -20, 2, -50, 6},
    { 0, 4, 2, 4},
    { 0, 0, -25, -17},
    { -5, 2, -3, 2},
    { -4, -3, -2, -3},
    { 3, -5, 3, -3},
    { 17, -11, 42, -27},
    { 4, 1, 4, 3},
    { 0, 0, 26, 15},
    { 3, -4, 5, -4},
    { 20, -3, 50, -7},
    { -3, 2, -3, 4},
    { -5, 0, -3, 0},
    { 0, -4, 0, -2},
    { -4, 0, -4, 2},
    { 2, -3, 4, -3},
    { -4, -4, -2, -4},
    { -4, 3, -4, 5},
    { -2, -2, -2, 0},
    { -2, 0, -2, 2},
    { 0, 3, 2, 3},
    { 0, 0, -27, 14},
    { 0, 0, -29, 6},
    { -2, 3, -2, 5},
    { 18, 9, 45, 22},
    { 20, 0, 50, 0},
    { 4, -2, 4, 0},
    { -16, -11, -41, -28},
    { 11, 17, 28, 42},
    { -5, -19, -13, -48},
    { 5, -19, 14, -48},
    { 2, -1, 4, -1},
    { -2, -3, -2, -1},
    { 1, 1, 3, 1},
    { -2, -4, -2, -2},
    { 4, 3, 4, 5},
    { 0, 0, 28, -12},
    { 4, 0, 4, 2},
    { -4, 1, -4, 3},
    { -3, -4, -3, -2},
    { 3, -1, 5, -1},
    { -18, -8, -46, -21},
    { -2, 1, -2, 3},
    { -20, 4, -49, 10},
    { 0, 0, 30, -4},
    { -1, -3, -1, -1},
    { -3, -5, -3, -3},
    { 0, 0, 14, 26},
    { 14, 14, 35, 36},
    { -2, -1, 0, -1},
    { 1, -3, 1, -1},
    { 3, 0, 3, 2},
    { 4, -1, 4, 1},
    { 0, -3, 2, -3},
    { -20, -3, -49, -8},
    { -1, 0, 1, 0},
    { -6, 19, -15, 48},
    { 0, 0, 0, 2},
    { 2, 3, 2, 5},
    { -3, 1, -3, 3},
    { 0, -2, 2, -2},
    { -12, 16, -31, 40},
    { 0, -1, 2, -1},
    { 4, -4, 4, -2},
    { -1, 4, 1, 4},
    { 0, -1, 0, 1},
    { -3, -2, -1, -2},
    { -1, -4, 1, -4},
    { 2, 4, 4, 4},
    { 1, -2, 1, 0},
    { -8, -18, -21, -45},
    { -3, -2, -3, 0},
    { -16, 12, -40, 30},
    { 0, 0, 18, -24},
    { -2, -5, -2, -3},
    { -19, -5, -49, -12},
    { 13, 16, 31, 39},
    { 1, -1, 3, -1},
    { -4, 20, -11, 49},
    { -5, 1, -3, 1},
    { -1, 1, -1, 3},
    { -4, -2, -4, 0},
    { -14, 15, -34, 37},
    { 0, 0, -19, -23},
    { -1, -1, -1, 1},
    { 19, 7, 47, 17},
    { -1, 2, 1, 2},
    { -2, -3, 0, -3},
    { 1, -1, 1, 1},
    { 3, 1, 5, 1},
    { 1, 0, 3, 0},
    { -1, 20, -2, 50},
    { -2, 2, 0, 2},
    { 3, -2, 5, -2},
    { -1, -2, -1, 0},
    { 3, 20, 7, 49},
    { -4, 0, -2, 0},
    { 7, -19, 18, -47},
    { -3, 0, -1, 0},
    { -4, 2, -2, 2},
    { -4, -1, -2, -1},
    { -15, 13, -37, 34},
    { 0, 0, -1, 30},
    { -4, 2, -4, 4},
    { -1, -4, -1, -2},
    { -1, -2, 1, -2},
    { -1, 2, -1, 4},
    { -3, 0, -3, 2},
    { 0, 0, 11, -28},
    { -5, -2, -3, -2},
    { -20, -1, -50, -3},
    { -2, 4, 0, 4},
    { 0, -5, 0, -3},
    { -11, 17, -27, 42},
    { 4, -3, 4, -1},
    { 1, -4, 1, -2},
    { -4, -3, -4, -1},
    { -14, -14, -36, -35},
    { -1, 0, -1, 2},
    { -4, -4, -4, -2},
    { 0, 0, -5, -30},
    { 0, -3, 0, -1},
    { 2, 3, 4, 3},
    { 2, 2, 4, 2}
};
#endif
