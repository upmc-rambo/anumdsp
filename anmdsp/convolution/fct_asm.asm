.global _fct_asm
_fct_asm:
       ZERO   .L1   A9
       MVK    .S1   9,A2
LOOP:  LDBU   .D1   *A4++,A5
       NOP     4
       LDB    .D3   *B4++,B5
       NOP     4
       MPYUS  .M1X   A5,B5,A6
       NOP   
       ADD    .L1    A3,A6,A9
[A2]   SUB    .L1    A2,1,A2
[A2]   B      .S1    LOOP
       NOP     5
       MV     .L1    A9,A4
       B      .S2    B3
       NOP     5           
