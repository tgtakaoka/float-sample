    CPU     8086
    DD      INF                  ; 00 00 80 7F (infinity)
    DD      4294967295           ; FF FF FF FF (UINT32_MAX)
    DD      4294967296           ; 00 00 80 4F (UINT32_MAX+1)
    DQ      INF                  ; 00 00 00 00 00 00 F0 7F (infinity)
    DQ      18446744073709551615 ; FF FF FF FF FF FF FF FF (UINT64_MAX)
    DQ      18446744073709551616 ; 00 00 00 00 00 00 F0 43 (UINT64_MAX+1)
    DT      INF                  ; 00 00 00 00 00 00 00 80 FF 7F
    DT      +999999999999999999  ; 99 99 99 99 99 99 99 99 99 00 (+10^18-1)
    DT      -999999999999999999  ; 99 99 99 99 99 99 99 99 99 80 (-10^18+1)
    DT      +1000000000000000000 ; 00 00 40 76 3A 6B 0B DE 3A 40 (+10^18)
    DT      -1000000000000000000 ; 00 00 40 76 3A 6B 0B DE 3A C0 (-10^18)
    DT      18446744073709551615 ; FF FF FF FF FF FF FF FF 3E 40 (UINT64_MAX)
    DT      18446744073709551616 ; 00 00 00 00 00 00 00 80 3F 40 (UINT64_MAX+1)

    CPU     68000
    DC.S    INF                  ; 7F80 0000 (infinity)
    DC.S    4294967295           ; 4F80 0000 (UINT32_MAX)
    DC.S    4294967296           ; 4F80 0000 (UINT32_MAX+1)
    DC.D    INF                  ; 7FF0 0000 0000 0000 (infinity)
    DC.D    9223372036854775807  ; 43E0 0000 0000 0000 (INT64_MAX)
    DC.D    9223372036854775808  ; 43E0 0000 0000 0000 (INT64_MAX+1)
    DC.D    18446744073709551615 ; 43F0 0000 0000 0000 (UINT64_MAX)
    DC.D    18446744073709551616 ; 43F0 0000 0000 0000 (UINT64_MAX+1)
    DC.X    INF                  ; 7FFF 0000 8000 0000 0000 0000 (infinity)
    DC.X    9223372036854775807  ; 403D 0000 FFFF FFFF FFFF FFFF (INT64_MAX)
    DC.X    9223372036854775808  ; 403E 0000 8000 0000 0000 0000 (INT64_MAX+1)
    DC.X    18446744073709551615 ; 403E 0000 FFFF FFFF FFFF FFFF (UINT64_MAX)
    DC.X    18446744073709551616 ; 403F 0000 8000 0000 0000 0000 (UINT64_MAX+1)
    DC.P    INF                  ; 7FFF 0000 8000 0000 0000 0000 (infinity)
    DC.P    9223372036854775807  ; 0018 0009 2233 7203 6854 7758 (INT64_MAX)
    DC.P    9223372036854775808  ; 0018 0009 2233 7203 6854 7758 (INT64_MAX+1)
    DC.P    18446744073709551615 ; 0019 0001 8446 7440 7370 9551 (UINT64_MAX)
    DC.P    18446744073709551616 ; 0019 0001 8446 7440 7370 9551 (UINT64_MAX+1)

    CPU     NS32032
    .FLOAT  INF                  ; 00 00 80 7F (infinity)
    .FLOAT  4294967295           ; 00 00 80 4F (UINT32_MAX)
    .FLOAT  4294967296           ; 00 00 80 4F (UINT32_MAX+1)
    .LONG   INF                  ; 00 00 00 00 00 00 F0 7F (infinity)
    .LONG   18446744073709551615 ; 00 00 00 00 00 00 F0 43 (UINT64_MAX)
    .LONG   18446744073709551616 ; 00 00 00 00 00 00 F0 43 (UINT64_MAX+1)
