#include "mult.h"

//cette fonction permet la multiplication entre 2 valeurs: A sur A_bits, B sur B_bits
int mult( unsigned char* A, int A_bits, unsigned char* B, int B_bits){
	
	int P_bits, ii, jj, res = 0;
	P_bits = A_bits + B_bits - 1;
	unsigned char MUX_A[B_bits];
	unsigned char MUX_S[B_bits];
	unsigned char Sortie[B_bits][A_bits];
	unsigned char Si[B_bits][A_bits];
	unsigned char Cout[B_bits][A_bits];
	unsigned char Cin[B_bits][A_bits];
	unsigned char C[P_bits];
	unsigned char Not_A;
        unsigned char ov;
	            ov = 0;
	            for(ii = 0 ; ii != B_bits ; ii++){
					if(ii == 0){
				            if(B[ii] == 1){
					               MUX_A[ii] = 0;
					               MUX_S[ii] = 1;
						      }
				            else{
				             MUX_A[ii] = 0;
					         MUX_S[ii] = 0;	
						    }					
					}
					if(ii != 0){
				         if(B[ii] < B[ii-1]){
					         MUX_A[ii] = 1;
					         MUX_S[ii] = 0;
						 }
					else if(B[ii] > B[ii-1]){
					         MUX_A[ii] = 0;
					         MUX_S[ii] = 1;						     						
				         } 
				    else {
				             MUX_A[ii] = 0;
					         MUX_S[ii] = 0;
                         }
                    }     

                         for(jj = 0 ; jj != A_bits ; jj++){
													 Not_A=  (A[jj]==1)? 0:1;												
											         Sortie[ii][jj]	= (MUX_A[ii] & A[jj]) | (MUX_S[ii] & (Not_A));										  
						 }
				}
				for(ii = 0 ; ii != B_bits ; ii++){
			    Cin[ii][0] = MUX_S[ii];
			    }
			    
	            for(ii = 0 ; ii != A_bits ; ii ++){
					    if( ii == 0){
						    Si[0][0] = 0 ^ Sortie[0][0] ^ Cin[0][0];
		                    Cout[0][0] = ((Sortie[0][0] ^ 0) & Cin[0][0]) | (Sortie[0][0] & 0);
					}   
					    else {
				            Si[0][ii] = 0 ^ Sortie[0][ii] ^ Cout[0][ii-1];
		                    Cout[0][ii] = ((Sortie[0][ii] ^ 0) & Cout[0][ii-1]) | (Sortie[0][ii] & 0);
						}
						     	
				}
				
				for(ii = 1 ; ii != B_bits ; ii ++){
					     for(jj = 0 ; jj != (A_bits - 1) ; jj ++){
							    if( jj == 0){
							    Si[ii][jj] = Si[ii-1][jj+1] ^ Sortie[ii][jj] ^ Cin[ii][jj] ; 
							    Cout[ii][jj] = (((Si[ii-1][jj+1] ^ Sortie[ii][jj]) & Cin[ii][jj]) | (Si[ii-1][jj+1] & Sortie[ii][jj]));
							}  
							    else{
				                Si[ii][jj] = Si[ii-1][jj+1] ^ Sortie[ii][jj] ^ Cout[ii][jj-1] ; 
							    Cout[ii][jj] = (((Si[ii-1][jj+1] ^ Sortie[ii][jj]) & Cout[ii][jj-1]) | (Si[ii-1][jj+1] & Sortie[ii][jj]));
							}
						 }
						        Si[ii][A_bits-1] = Si[ii-1][A_bits-1] ^ Sortie[ii][A_bits-1] ^ Cout[ii][A_bits-2] ; 
							    Cout[ii][A_bits-1] = (((Si[ii-1][A_bits-1] ^ Sortie[ii][A_bits-1]) & Cout[ii][A_bits-2]) | (Si[ii-1][A_bits-1] & Sortie[ii][A_bits-1]));
				}
				
				for(ii = 0 ; ii != B_bits ; ii ++){
					C[ii] = Si[ii][0]; 
				}
				
				for(ii = 1 ; ii != A_bits ; ii ++){
					C[B_bits+ii-1] = Si[B_bits-1][ii]; 
				}
				
				C[P_bits] = Cout[B_bits-1][A_bits-1] ^ Cout[B_bits-1][A_bits-2] ^ Si[B_bits-1][A_bits-1];

			    if(C[P_bits] == 0){
					for(ii = 0 ; ii <= P_bits ; ii++){
					        res = res + C[ii] * (1<<ii);
				    } 
				}
				else if(C[P_bits] == 1){
					for(ii = P_bits ; ii >= 0 ; ii--){
					         if(C[ii] == 0) C[ii] = 1;
					         else C[ii] = 0;
				    }
				    for(ii = P_bits ; ii >= 0 ; ii--){
					         res = res + C[ii] * (1<<ii);
				    } 
				    res = res + 1;
				    res = -res;

				}

			return res;
	            
};
