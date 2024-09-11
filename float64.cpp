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

const auto DBL_SUBN_MAX = DBL_MIN - DBL_TRUE_MIN;
const auto DBL_HEX_DIG = DBL_MANT_DIG / 4;

constexpr auto INT53_MAX = 0x1.0P+52 - 1;
constexpr auto INT53_MIN = -0x1.0P+52;
constexpr auto UINT53_MAX = 0x1.0P+53 - 1;

void i64(const char *msg, int v) {
    printf("%-16s = %6d\n", msg, v);
}

void f64(const char *msg, double v) {
    char hex[DBL_HEX_DIG + 16];
    char dec[DBL_DECIMAL_DIG + 16];
    snprintf(hex, sizeof(hex), "%+.*A", DBL_HEX_DIG, v);
    snprintf(dec, sizeof(dec), "%+.*g", DBL_DECIMAL_DIG, v);
    printf("%-16s = %-*s    %s\n", msg, DBL_HEX_DIG + 11, hex, dec);
}

int main() {
    i64("DBL_DIG", DBL_DIG);
    i64("DBL_DECIMAL_DIG", DBL_DECIMAL_DIG);
    i64("DBL_MANT_DIG", DBL_MANT_DIG);
    i64("DBL_HEX_DIG", DBL_HEX_DIG);
    i64("DBL_MAX_EXP", DBL_MAX_EXP);
    i64("DBL_MIN_EXP", DBL_MIN_EXP);
    i64("DBL_MAX_10_EXP", DBL_MAX_10_EXP);
    i64("DBL_MIN_10_EXP", DBL_MIN_10_EXP);

    f64("INT53_MAX", INT53_MAX);
    f64("INT53_MIN", INT53_MIN);
    f64("UINT53_MAX", UINT53_MAX);
    f64("UINT53_MAX+1", UINT53_MAX + 1);

    f64("DBL_MAX", DBL_MAX);
    f64("DBL_MIN", DBL_MIN);
    f64("DBL_SUBN_MAX", DBL_SUBN_MAX);
    f64("DBL_TRUE_MIN", DBL_TRUE_MIN);
    f64("DBL_EPSILON", DBL_EPSILON);

    return 0;
}

// Local Variables:
// mode: c++
// c-basic-offset: 4
// tab-width: 4
// End:
// vim: set ft=cpp et ts=4 sw=4:
