#include <stdio.h>

void MULT( unsigned char* A, int A_bits, unsigned char* B, int B_bits){
	
	int P_bits, ii, jj;
	P_bits = A_bits + B_bits - 1;
	unsigned char MUX_A[B_bits];
	unsigned char MUX_S[B_bits];
	unsigned char Sortie[B_bits][A_bits];
	unsigned char Si[B_bits][A_bits];
	unsigned char Cout[B_bits][A_bits];
	unsigned char Cin[B_bits][A_bits];
	unsigned char C[P_bits];
	
	            for(ii = 0 ; ii != B_bits ; ii++){
					if(ii == 0){
				            if(B[ii] == 1){
					               MUX_A[ii] = 0;
					               MUX_S[ii] = 1;
						      }
				            else
				             MUX_A[ii] = 0;
					         MUX_S[ii] = 0;						
					}
				    else if(B[ii] < B[ii-1]){
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
                         for(jj = 0 ; jj != A_bits ; jj++){
											         Sortie[ii][jj]	= ((MUX_A[ii] & A[jj]) | (MUX_S[ii] & (!A[jj])));
											         //printf("Sortie[%d][%d]=%d ",ii, jj , Sortie[ii][jj]);
						 }
						 //printf("\n");
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
				            Si[0][ii] = 0 ^ Sortie[0][ii] ;
		                    Cout[0][ii] = ((Sortie[0][ii] ^ 0) & Cout[0][ii-1]) | (Sortie[0][ii] & 0);
					}
						     	
				}
				
				for(ii = 1 ; ii != B_bits ; ii ++){
					     for(jj = 0 ; jj != (A_bits - 1) ; jj ++){
							    if( jj == 0){
							    Si[ii][jj] = Si[ii-1][jj+1] ^ Sortie[ii][jj] ^ Cin[ii][jj] ; 
							    Cout[ii][jj] = (((Si[ii-1][jj+1] ^ Sortie[ii][jj]) & Cin[ii][0]) | (Si[ii-1][jj+1] & Sortie[ii][jj]));
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
				
	            
	            for(ii = P_bits ; ii >= 0 ; ii--){
					printf("tab_C[%d]=%d ",ii , C[ii]);
				}
	            
};






int main(int argc, char** argv){

                   int i, i1=4, i2=3;
                   unsigned char A[10] = { 0,0,0,0,0,0,0,0,0,0 };
                   unsigned char B[10] = { 0,0,0,0,0,0,0,0,0,0 };
                 
                   for (i = 0 ; i != i1; i++){
                         scanf("%d", &A[i]);
                   }
                   for (i = 0 ; i != i2; i++){
                         scanf("%d", &B[i]);
                   }
  
		           for (i = i1-1 ; i >= 0; i--){
			             printf("tab_A[%d]=%d ",i , A[i]);
		           }
		           printf("\n");
		           for (i = i2-1 ; i >= 0; i--){
			             printf("tab_B[%d]=%d ",i , B[i]);
		           }
		           printf("\n");
		           
		           MULT(A, i1, B, i2); 

		          
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
