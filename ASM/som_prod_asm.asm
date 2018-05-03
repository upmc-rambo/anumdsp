		.global	_som_prod_asm

_som_prod_asm:
		MVKL .S1 9, A2 ; init cpt
		MVKL .S1 0, A9 ; init accu

loop:
		LDBU  .D1 *A4++, A5 ; buf px ---5 cycles
		NOP 4
		LDH   .D2 *B4++, B5 ; buf kernal ----5 cycles
		NOP 4
		MPYUS .M1  A5, B5, A6 ; A5 * B5 = A6--- 2 cycles
		NOP 1
		ADD   .L1  A6, A9, A9 ; accu
	[A2]SUB   .L1  A2, 1, A2 ; cpt--
    [A2]B     .S1  loop ;                  -----6 cycles
		NOP 5
		
		MV    .S1  A9, A4 ; return value
		B     .S2  B3 ; return address
		NOP 5
