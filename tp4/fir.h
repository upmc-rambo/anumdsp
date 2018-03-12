#ifndef H_FIR
#define H_FIR

void ADDITION(short * A,short * B,short  cin,short * S,short * cout,short N);
void MULTBOOTH(short * A,short * B,short  NB_BITS_A,short NB_BITS_B,short * S);
void FIR(short *X, short K, short *A, short C, short L, short **Y);

#endif
