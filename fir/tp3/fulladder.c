#include "fulladder.h"

// fonction ADD permet l'addition de 2 valeurs en 4 bits 
unsigned char ADD (unsigned char* tab_A, unsigned char* tab_B, unsigned char rin, unsigned char* tab_S,unsigned char rout){
		
		int i;
		unsigned char pi[100];
		unsigned char gi[100];
		unsigned char ri[100];
		
		for (i = 0 ; i < 4 ; i++){

			pi[i] = tab_A[i] ^ tab_B[i];
			gi[i] = tab_A[i] & tab_B[i];
			

			if (i == 0){		
				ri[i] = gi[i] | ( pi[i] & rin ) ;
				tab_S[i] = tab_A[i] ^ tab_B[i] ^ rin;
				
			}else{	
				ri[i] = gi[i] | ( pi[i] & ri[i-1] ) ;
				tab_S[i] = tab_A[i] ^ tab_B[i] ^ ri[i-1];		
			}
			rout = ri[3];		
		}

        return rout;
};

// fonction NBITS_ADDER() permet l'addition de 2 valeurs en N bits, N doit être multiplié par 4
int NBITS_ADDER (unsigned char* tab_A, unsigned char* tab_B, unsigned char rin, unsigned char* tab_S,unsigned char rout, int N){
	
        int i, n, res=0;
        unsigned char in, out1, out, p=0;
        unsigned char tab_out[10]={0,0,0,0,0,0,0,0,0,0};
        unsigned char T1[4];
        unsigned char T2[4];
        unsigned char T[4];
        unsigned char pi[4];
        n = N/4;
        
                        T1[0] = tab_A[0];
						T1[1] = tab_A[1];
						T1[2] = tab_A[2];
						T1[3] = tab_A[3];
						
						T2[0] = tab_B[0];
						T2[1] = tab_B[1];
						T2[2] = tab_B[2];
						T2[3] = tab_B[3];
						
					    out1 = ADD(T1, T2, 0, T,out);
					    tab_out[1]= out1;
					    in = tab_out[1];
					    	
					    tab_S[0] = T[0];
					    tab_S[1] = T[1];
					    tab_S[2] = T[2];
					    tab_S[3] = T[3];
					    	
                    for(i = 2; i <= n; i++){
						if(p == 0){
						      in = tab_out[i-1]; 
						}
								  
						T1[0] = tab_A[i*4-4];
						T1[1] = tab_A[i*4-3];
						T1[2] = tab_A[i*4-2];
						T1[3] = tab_A[i*4-1];
						
						T2[0] = tab_B[i*4-4];
						T2[1] = tab_B[i*4-3];
						T2[2] = tab_B[i*4-2];
						T2[3] = tab_B[i*4-1];
						
						pi[0] = tab_A[i*4-4] ^ tab_B[i*4-4];
						pi[1] = tab_A[i*4-3] ^ tab_B[i*4-3];
						pi[2] = tab_A[i*4-2] ^ tab_B[i*4-2];
						pi[3] = tab_A[i*4-1] ^ tab_B[i*4-1];
						p = pi[0] & pi[1] & pi[2] & pi[3];
						
					    out1 = ADD(T1, T2, in, T,out);
					    tab_out[i] = out1;
					    	
					    tab_S[i*4-4] = T[0];
					    tab_S[i*4-3] = T[1];
					    tab_S[i*4-2] = T[2];
					    tab_S[i*4-1] = T[3];				
					}
					    for(i = 0; i < N; i++){
							res = res + tab_S[i] * (1<<i);
						}
						    res = res + tab_out[n] * (1<<i);
							
							return res;
        
        
        
};





