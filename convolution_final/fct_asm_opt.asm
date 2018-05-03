	.global _fct_asm_opt
_fct_asm_opt:
       ZERO   .L1   A9

        LDBU   .D1   *A4++,A5
   ||   LDB    .D3   *B4++,B5
        
        LDBU   .D1   *A4++,A5
   ||   LDB    .D3   *B4++,B5
		
		LDBU   .D1   *A4++,A5
   ||	LDB    .D3   *B4++,B5
        
        LDBU   .D1   *A4++,A5
   ||   LDB    .D3   *B4++,B5
		
    	LDBU   .D1   *A4++,A5
   ||   LDB    .D3   *B4++,B5
        
        LDBU   .D1   *A4++,A5
   ||   LDB    .D3   *B4++,B5
   ||   MPYUS  .M1X   A5,B5,A6
		
    	LDBU   .D1   *A4++,A5
   ||   LDB    .D3   *B4++,B5
   ||   MPYUS  .M1X   A5,B5,A6
		
    	LDBU   .D1   *A4++,A5
   ||   LDB    .D3   *B4++,B5
   ||   MPYUS  .M1X   A5,B5,A6
   ||	ADD    .L1    A9,A6,A9
		
    	LDBU   .D1   *A4++,A5
   ||   LDB    .D3   *B4++,B5
   ||   MPYUS  .M1X   A5,B5,A6
   ||	ADD    .L1    A9,A6,A9
   
        MPYUS  .M1X   A5,B5,A6
   ||	ADD    .L1    A9,A6,A9
   
        MPYUS  .M1X   A5,B5,A6
   ||	ADD    .L1    A9,A6,A9
   
        MPYUS  .M1X   A5,B5,A6
   ||	ADD    .L1    A9,A6,A9
   
        MPYUS  .M1X   A5,B5,A6
   ||	ADD    .L1    A9,A6,A9
   
        MPYUS  .M1X   A5,B5,A6
   ||	ADD    .L1    A9,A6,A9
   
   	    ADD    .L1    A9,A6,A9

     	ADD    .L1    A9,A6,A9
       
       MV     .L1    A9,A4
       B      .S2    B3
       NOP     5           
