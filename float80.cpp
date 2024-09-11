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

const auto UINT65_MIN = static_cast<long double>(UINT64_MAX) + 1;
const auto LDBL_SUBN_MAX = LDBL_MIN - LDBL_TRUE_MIN;
const auto LDBL_HEX_DIG = LDBL_MANT_DIG / 4 - 1;

void i64(const char *msg, int v) {
    printf("%-16s = %6d\n", msg, v);
}

void f80(const char *msg, long double v) {
    char hex[LDBL_HEX_DIG + 16];
    char dec[LDBL_DECIMAL_DIG + 16];
    snprintf(hex, sizeof(hex), "%+.*LA", LDBL_HEX_DIG, v);
    snprintf(dec, sizeof(dec), "%+.*Lg", LDBL_DECIMAL_DIG, v);
    printf("%-16s = %-*s    %s\n", msg, LDBL_HEX_DIG + 12, hex, dec);
}

int main() {
    i64("LDBL_DIG", LDBL_DIG);
    i64("LDBL_DECIMAL_DIG", LDBL_DECIMAL_DIG);
    i64("LDBL_MANT_DIG", LDBL_MANT_DIG);
    i64("LDBL_HEX_DIG", LDBL_HEX_DIG);
    i64("LDBL_MAX_EXP", LDBL_MAX_EXP);
    i64("LDBL_MIN_EXP", LDBL_MIN_EXP);
    i64("LDBL_MAX_10_EXP", LDBL_MAX_10_EXP);
    i64("LDBL_MIN_10_EXP", LDBL_MIN_10_EXP);

    f80("INT64_MAX", INT64_MAX);
    f80("INT64_MIN", INT64_MIN);
    f80("UINT64_MAX", UINT64_MAX);
    f80("UINT64_MAX+1", UINT65_MIN);

    f80("LDBL_MAX", LDBL_MAX);
    f80("LDBL_MIN", LDBL_MIN);
    f80("LDBL_SUBN_MAX", LDBL_SUBN_MAX);
    f80("LDBL_TRUE_MIN", LDBL_TRUE_MIN);
    f80("LDBL_EPSILON", LDBL_EPSILON);

    return 0;
}

// Local Variables:
// mode: c++
// c-basic-offset: 4
// tab-width: 4
// End:
// vim: set ft=cpp et ts=4 sw=4:
