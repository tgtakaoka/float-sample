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

const auto FLT_SUBN_MAX = FLT_MIN - FLT_TRUE_MIN;
const auto FLT_HEX_DIG = FLT_MANT_DIG / 4;

constexpr auto INT24_MAX = static_cast<float>(INT32_C(0x007FFFFF));
constexpr auto INT24_MIN = static_cast<float>(-INT32_C(0x00800000));
constexpr auto UINT24_MAX = static_cast<float>(UINT32_C(0x00FFFFFF));

void i32(const char *msg, int v) {
    printf("%-16s = %6d\n", msg, v);
}

void f32(const char *msg, float v) {
    char hex[FLT_HEX_DIG + 16];
    char dec[FLT_DECIMAL_DIG + 16];
    snprintf(hex, sizeof(hex), "%+.*A", FLT_HEX_DIG, v);
    snprintf(dec, sizeof(dec), "%+.*g", FLT_DECIMAL_DIG, v);
    printf("%-16s = %-*s    %s\n", msg, FLT_HEX_DIG + 11, hex, dec);
}

void f32r(const char *msg, float v) {
    union {
        float f32;
        uint32_t u32;
        ;
    } data;
    data.f32 = v;
    char hex[FLT_HEX_DIG + 16];
    char dec[FLT_DECIMAL_DIG + 16];
    const uint16_t tag = data.u32 >> (FLT_MANT_DIG - 1);
    snprintf(hex, sizeof(hex), " 0X%d.%06X %03X", (tag & 0x7F) == 0 ? 0 : 1,
            (data.u32 & UINT32_C(0x007FFFFF)) << 1, tag);
    snprintf(dec, sizeof(dec), "%+.*g", FLT_DECIMAL_DIG, v);
    printf("%-16s = %-*s    %s\n", msg, FLT_HEX_DIG + 12, hex, dec);
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

    f32("INT24_MAX", INT24_MAX);
    f32("INT24_MIN", INT24_MIN);
    f32("UINT24_MAX", UINT24_MAX);
    f32("UINT24_MAX+1", UINT24_MAX + 1);

    f32("INT64_MAX", INT64_MAX);
    f32("INT64_MIN", INT64_MIN);
    f32("UINT64_MAX", UINT64_MAX);
    f32("UINT64_MAX+1", static_cast<float>(UINT64_MAX) + 1);

    f32("FLT_MAX", FLT_MAX);
    f32("FLT_MIN", FLT_MIN);
    f32("FLT_SUBN_MAX", FLT_SUBN_MAX);
    f32("FLT_TRUE_MIN", FLT_TRUE_MIN);
    f32("FLT_EPSILON", FLT_EPSILON);

    f32r("+HUGE_VALF", +HUGE_VALF);
    f32r("-HUGE_VALF", -HUGE_VALF);
    f32r("+NAN", +NAN);
    f32r("-NAN", -NAN);

    return 0;
}

// Local Variables:
// mode: c++
// c-basic-offset: 4
// tab-width: 4
// End:
// vim: set ft=cpp et ts=4 sw=4:
