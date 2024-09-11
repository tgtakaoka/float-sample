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
#include "quadmath.h"

const auto UINT65_MIN = static_cast<__float128>(UINT64_MAX) + 1;
#if !defined(FLT128_DECIMAL_DIG)
const auto FLT128_DECIMAL_DIG = FLT128_DIG + 2;
#endif
#if !defined(FLT128_TRUE_MIN)
const auto FLT128_TRUE_MIN = ldexpq(1, FLT128_MIN_EXP - FLT128_MANT_DIG);
#endif
const auto FLT128_SUBN_MAX = FLT128_MIN - FLT128_TRUE_MIN;
const auto FLT128_HEX_DIG = FLT128_MANT_DIG / 4;

void i64(const char *msg, int v) {
    printf("%-18s = %6d\n", msg, v);
}

void f128(const char *msg, __float128 v) {
    char hex[FLT128_HEX_DIG + 16];
    char dec[FLT128_DECIMAL_DIG + 16];
    quadmath_snprintf(hex, sizeof(hex), "%+.*QA", FLT128_HEX_DIG, v);
    quadmath_snprintf(dec, sizeof(dec), "%+.*Qg", FLT128_DECIMAL_DIG, v);
    printf("%-18s = %-*s    %s\n", msg, FLT128_HEX_DIG + 12, hex, dec);
}

int main() {
    i64("FLT128_DIG", FLT128_DIG);
    i64("FLT128_DECIMAL_DIG", FLT128_DECIMAL_DIG);
    i64("FLT128_MANT_DIG", FLT128_MANT_DIG);
    i64("FLT128_HEX_DIG", FLT128_HEX_DIG);
    i64("FLT128_MAX_EXP", FLT128_MAX_EXP);
    i64("FLT128_MIN_EXP", FLT128_MIN_EXP);
    i64("FLT128_MAX_10_EXP", FLT128_MAX_10_EXP);
    i64("FLT128_MIN_10_EXP", FLT128_MIN_10_EXP);

    f128("INT64_MAX", INT64_MAX);
    f128("INT64_MIN", INT64_MIN);
    f128("UINT64_MAX", UINT64_MAX);
    f128("UINT64_MAX+1", UINT65_MIN);

    f128("FLT128_MAX", FLT128_MAX);
    f128("FLT128_MIN", FLT128_MIN);
    f128("FLT128_SUBN_MAX", FLT128_SUBN_MAX);
    f128("FLT128_TRUE_MIN", FLT128_TRUE_MIN);
    f128("FLT128_EPSILON", FLT128_EPSILON);

    return 0;
}

// Local Variables:
// mode: c++
// c-basic-offset: 4
// tab-width: 4
// End:
// vim: set ft=cpp et ts=4 sw=4:
