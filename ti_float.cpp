#include <math.h>
#include <stdint.h>
#include <stdio.h>

void ti_float(uint32_t u32, double val) {
    auto frac = u32 & UINT32_C(0x007FFFFF);
    const auto one = UINT32_C(0x00800000);
    const auto sign = u32 & UINT32_C(0x00800000);
    if (sign) {
      frac |= UINT32_C(0xFF000000);
    } else {
      frac |= UINT32_C(0x00800000);
    }
    auto ti_val = static_cast<int32_t>(frac) / static_cast<double>(one);
    printf("%08X %16A(%20g) %16A(%20g)\n", u32, ti_val, ti_val, val, val);
}    

int main() {
  ti_float(UINT32_C(0x007FFFFF), 2.0 - pow(2.0, -23));
  ti_float(UINT32_C(0x00000000), 1.0);
  ti_float(UINT32_C(0x00800000), -2.0);
  ti_float(UINT32_C(0x00FFFFFF), -1 - pow(2.0, -23));
  return 0;
}
