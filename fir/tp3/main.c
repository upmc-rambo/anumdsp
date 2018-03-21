#include <stdio.h>
#include "change_to_binary.h"
#include "mult.h"
#include "fulladder.h"


int main(int argc, char** argv){

                   int i, j, a, b, c, d, e, f, g, h, out, N=12;
                   unsigned char H[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char G[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char F[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char E[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char D[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char S[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char A[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char B[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char C[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char A0[12] = { 1,0,0,0,0,0,0,0,0,0,0,0};
                   unsigned char A1[12] = { 0,1,0,0,0,0,0,0,0,0,0,0};
                   unsigned char A2[12] = { 1,1,0,0,0,0,0,0,0,0,0,0};
                   unsigned char Y[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
                   
                   printf("RIF:\n");
                   printf("ao = 1, a1 = 2, a3 = 3\n");                   
                   printf("tape 3 enter values:\n");
                   printf("x[0]=");
                   scanf("%d",&a);
                   printf("x[1]=");
                   scanf("%d",&b);
                   printf("x[2]=");
                   scanf("%d",&c);
                   
                   change_to_binary(a,A,N);
                   change_to_binary(b,B,N);
                   change_to_binary(c,C,N);
                   			   				   
		           /*for (i = N-1 ; i >= 0; i--){
			             printf("tab_A[%d]=%d ",i , A[i]);
		           }
		           printf("\n");		           		         
		           
		           for (i = N-1 ; i >= 0; i--){
			             printf("tab_B[%d]=%d ",i , B[i]);
		           }
		           printf("\n");
		           
		           for (i = N-1 ; i >= 0; i--){
			             printf("tab_C[%d]=%d ",i , C[i]);
		           }
		           printf("\n");*/
		           		        
		           printf("\n");printf("\n");
		           
		           //calcul de Y[0]
		           Y[0] = mult(A, 6, A0, 6);
		           printf("Y[0]=%d ",Y[0]);
		           
		           //calcul de Y[1]
		           d = mult(A, 6, A1, 6);
		           change_to_binary(d,D,N);
		           e = mult(B, 6, A0, 6);
		           change_to_binary(e,E,N);
		           Y[1] = NBITS_ADDER (D, E, 0, S, out, N);
		           printf("Y[1]=%d ",Y[1]);
		           
		           //calcul de Y[2]
		           d = mult(A, 6, A2, 6);
		           change_to_binary(d,D,N);
		           e = mult(B, 6, A1, 6);
		           change_to_binary(e,E,N);
		           f = mult(C, 6, A0, 6);
		           change_to_binary(f,F,N);
		           d = NBITS_ADDER (D, E, 0, S, out, N);
		           change_to_binary(d,D,N);
		           Y[2] = NBITS_ADDER (D, F, 0, S, out, N);
		           printf("Y[2]=%d ",Y[2]);
		           
		           //calcul de Y[3]
		           g = mult(B, 6, A2, 6);
		           change_to_binary(g,G,N);
		           h = mult(C, 6, A1, 6);
		           change_to_binary(h,H,N);
		           Y[3] = NBITS_ADDER (G, H, 0, S, out, N);
		           printf("Y[3]=%d ",Y[3]);
		           
		           //calcul de Y[4]
		           Y[4] = mult(C, 6, A2, 6);
		           printf("Y[4]=%d ",Y[4]);
		           printf("Y[5]=%d ",Y[5]);
		           printf("Y[5]=%d ",Y[5]);		           
		          
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
