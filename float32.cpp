/*
 * Copyright 2024 Tadashi G. Takaoka
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <iomanip>
#include <ios>
#include <sstream>

const auto UINT33_MIN = static_cast<float>(UINT32_MAX) + 1;
const auto FLT_SUBN_MAX = FLT_MIN - FLT_TRUE_MIN;
const auto FLT_HEX_DIG = FLT_MANT_DIG / 4;
const auto FLT_HEXADECIMAL_DIG = 5 /*"[+-]0X[01]."*/ + FLT_HEX_DIG /* P[+-]xxx */ + 5;

void i32(const char *msg, int v) {
    printf("%-16s = %6d\n", msg, v);
}

void f32(const char *msg, float v) {
    std::ostringstream hex, dec;
    hex << std::uppercase << std::showpos << std::showpoint << std::setprecision(FLT_HEX_DIG)
        << std::hexfloat << v;
    dec << std::showpos << std::setprecision(FLT_DECIMAL_DIG) << std::defaultfloat << v;
    printf("%-16s = %-*s    %s\n", msg, FLT_HEXADECIMAL_DIG, hex.str().c_str(), dec.str().c_str());
}

int main() {
    i32("FLT_DIG", FLT_DIG);
    i32("FLT_DECIMAL_DIG", FLT_DECIMAL_DIG);
    i32("FLT_MANT_DIG", FLT_MANT_DIG);
    i32("FLT_HEX_DIG", FLT_HEX_DIG);
    i32("FLT_MAX_EXP", FLT_MAX_EXP);
    i32("FLT_MIN_EXP", FLT_MIN_EXP);
    i32("FLT_MAX_10_EXP", FLT_MAX_10_EXP);
    i32("FLT_MIN_10_EXP", FLT_MIN_10_EXP);

    f32("INT32_MAX", INT32_MAX);
    f32("INT32_MIN", INT32_MIN);
    f32("UINT32_MAX", UINT32_MAX);
    f32("UINT32_MAX+1", UINT33_MIN);

    f32("FLT_MAX", FLT_MAX);
    f32("FLT_MIN", FLT_MIN);
    f32("FLT_SUBN_MAX", FLT_SUBN_MAX);
    f32("FLT_TRUE_MIN", FLT_TRUE_MIN);
    f32("FLT_EPSILON", FLT_EPSILON);

    return 0;
}

// Local Variables:
// mode: c++
// c-basic-offset: 4
// tab-width: 4
// End:
// vim: set ft=cpp et ts=4 sw=4:
