#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

constexpr auto p32 = 8;
constexpr auto p64 = 16;
constexpr auto p80 = 20;

void print_f32(uint32_t v32, int prec = p32) {
    const auto f32 = static_cast<float>(v32);
    const auto exp = static_cast<int>(floorf(log10f(f32)));
    const auto fmt = (prec > exp && exp >= -4) ? 'f' : 'e';
    printf("%%8u=%8u prec=%d exp=%d fmt=%c %.*g\n", v32, prec, exp, fmt, prec, f32);
}

void print_f64(uint64_t v64, int prec = p64) {
    const auto f64 = static_cast<double>(v64);
    const auto exp = static_cast<int>(floor(log10(f64)));
    const auto fmt = (prec > exp && exp >= -4) ? 'f' : 'e';
    printf("%%16u=%16lu prec=%d exp=%2d fmt=%c %.*g\n", v64, prec, exp, fmt, prec, f64);
}

void print_f80(uint64_t v80, int prec = p80) {
    const auto f80 = static_cast<long double>(v80);
    const auto exp = static_cast<int>(floorl(log10l(f80)));
    const auto fmt = (prec > exp && exp >= -4) ? 'f' : 'e';
    printf("%%20u=%20lu prec=%d exp=%2d fmt=%c %.*Lg\n", v80, prec, exp, fmt, prec, f80);
}

void print_fmt(long double f80, int prec = p80) {
    printf("@@ A=%-23.15LA f=%-.*Lf e=%.*Le g=%.*Lg\n", f80, prec, f80, prec, f80, prec, f80);
}

constexpr auto UINT24_MAX = (UINT32_C(1) << 24) - 1;
constexpr auto UINT53_MAX = (UINT64_C(1) << 53) - 1;

int main() {
    printf("@@ FLT_DIG=%d DBL_DIG=%d LDBL_DIG=%d\n", FLT_DIG, DBL_DIG, LDBL_DIG);
    printf("@@ FLT_MANT_DIG=%d DBL_MANT_DIG=%d LDBL_MANT_DIG=%d\n", FLT_MANT_DIG, DBL_MANT_DIG,
            LDBL_MANT_DIG);

    const auto M_LOG2 = M_LN2 / M_LN10;
    const auto EXP_SUBNORMAL = -0x3FFF + 1 - 64;
    printf("@@ floor(EXP_SUBNORMAL * M_LOG2)=%d\n",
            static_cast<int>(floor(EXP_SUBNORMAL * M_LOG2)));
    const auto int64_min = static_cast<long double>(INT64_MIN);
    printf("@@     INT64_MIN=%+.15LA %+.21Lg\n", int64_min, int64_min);
    const auto int64_max = static_cast<long double>(INT64_MAX);
    printf("@@     INT64_MAX=%+.15LA %+.21Lg\n", int64_max, int64_max);
    const auto uint64_max = static_cast<long double>(UINT64_MAX);
    printf("@@    UINT64_MAX=%+.15LA %+.21Lg\n", uint64_max, uint64_max);
    const auto uint65_min = 0x8.000000000000000p+61L;
    printf("@@    UINT65_MIN=%+.15LA %+.21Lg\n", uint65_min, uint65_min);
    const auto LDBL_SUBN_MAX = LDBL_MIN - LDBL_TRUE_MIN;
    printf("@@      LDBL_MAX=%+.15LA %+.21Lg\n", LDBL_MAX, LDBL_MAX);
    printf("@@      LDBL_MIN=%+.15LA %+.21Lg\n", LDBL_MIN, LDBL_MIN);
    printf("@@ LDBL_SUBN_MAX=%+.15LA %+.21Lg\n", LDBL_SUBN_MAX, LDBL_SUBN_MAX);
    printf("@@ LDBL_TRUE_MIN=%+.15LA %+.21Lg\n", LDBL_TRUE_MIN, LDBL_TRUE_MIN);

    uint32_t v32 = 9;
    for (auto i = 0; i < 10; ++i) {
        print_f32(v32);
        if (v32 >= (UINT32_C(1) << 24) - 1)
            break;
        v32 = v32 * 10 + 9;
    }
    print_f32(UINT24_MAX);
    const auto fmax32 = static_cast<float>(UINT24_MAX) + 1;
    printf("%%8u=%8u prec=%d exp=%d fmt=%c %.*g\n", static_cast<uint32_t>(fmax32), p32,
            (int)floorf(log10f(fmax32)), 'g', p32, fmax32);

    uint64_t v64 = 9;
    for (auto i = 0; i < 19; ++i) {
        print_f64(v64);
        if (v64 >= (UINT64_C(1) << 53) - 1)
            break;
        v64 = v64 * 10 + 9;
    }
    print_f64(UINT53_MAX);
    const auto fmax64 = static_cast<double>(UINT53_MAX) + 1;
    printf("%%16u=%16lu prec=%d exp=%2d fmt=%c %.*g\n", static_cast<uint64_t>(fmax64), p64,
            (int)floor(log10(fmax64)), 'g', p64, fmax64);

    uint64_t v80 = 9;
    for (auto i = 0; i < 22; ++i) {
        print_f80(v80);
        if (v80 >= UINT64_MAX / 10)
            break;
        v80 = v80 * 10 + 9;
    }
    print_f80(UINT64_MAX);
    const auto fmax80 = static_cast<long double>(UINT64_MAX) + 1;
    printf("%%20u=%20lu prec=%d exp=%2d fmt=%c %.*Lg\n", static_cast<uint64_t>(fmax80), p80,
            (int)floorl(log10l(fmax80)), 'g', p80, fmax80);

    print_fmt(1.234567e-6L);
    print_fmt(1.234567e-5L);
    print_fmt(1.234567e-4L);
    print_fmt(1.234567e-3L);
    print_fmt(1.234567e-2L);
    print_fmt(1.234567e-1L);
    print_fmt(1.234567L);
    print_fmt(1.234567e+1L);
    print_fmt(1.234567e+2L);
    print_fmt(1.234567e+3L);
    print_fmt(1.234567e+4L);
    print_fmt(1.234567e+5L);
    print_fmt(1.234567e+6L);
    print_fmt(1.23e+6L);
    print_fmt(1.0e+6L);

    printf("@@ UINT32_MAX=%.7A\n", static_cast<float>(UINT32_MAX));

    return 0;
}
