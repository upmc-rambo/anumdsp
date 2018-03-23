#include "mult.h"
#include "change_to_binary.h"

//cette fonction permet la multiplication entre 2 valeurs: A sur A_bits, B sur B_bits
int mult( unsigned char* A, int A_bits, unsigned char* B, int B_bits,unsigned char* C){

    int P_bits, i, j, res = 0;
    P_bits = A_bits + B_bits - 1;
    unsigned char MUX_A[B_bits];
    unsigned char MUX_S[B_bits];
    unsigned char Sortie[B_bits][A_bits];
    unsigned char Si[B_bits][A_bits];
    unsigned char Cout[B_bits][A_bits];
    unsigned char Cin[B_bits][A_bits];
    unsigned char Not_A;
    unsigned char ov;
    ov = 0;
    for(i = 0 ; i != B_bits ; i++){
        if(i == 0){
            if(B[i] == 1){
                MUX_A[i] = 0;
                MUX_S[i] = 1;
            }
            else{
                MUX_A[i] = 0;
                MUX_S[i] = 0;
            }
        }
        if(i != 0){
            if(B[i] < B[i-1]){
                MUX_A[i] = 1;
                MUX_S[i] = 0;
            }
            else if(B[i] > B[i-1]){
                MUX_A[i] = 0;
                MUX_S[i] = 1;
            }
            else {
                MUX_A[i] = 0;
                MUX_S[i] = 0;
            }
        }
        
        for(j = 0 ; j != A_bits ; j++){
            Not_A=  (A[j]==1)? 0:1;
            Sortie[i][j]	= (MUX_A[i] & A[j]) | (MUX_S[i] & (Not_A));
        }
    }
    for(i = 0 ; i != B_bits ; i++){
        Cin[i][0] = MUX_S[i];
    }
    
    for(i = 0 ; i != A_bits ; i ++){
        if( i == 0){
            Si[0][0] = 0 ^ Sortie[0][0] ^ Cin[0][0];
            Cout[0][0] = ((Sortie[0][0] ^ 0) & Cin[0][0]) | (Sortie[0][0] & 0);
        }
        else {
            Si[0][i] = 0 ^ Sortie[0][i] ^ Cout[0][i-1];
            Cout[0][i] = ((Sortie[0][i] ^ 0) & Cout[0][i-1]) | (Sortie[0][i] & 0);
        }
        
    }
    
    for(i = 1 ; i != B_bits ; i ++){
        for(j = 0 ; j != (A_bits - 1) ; j ++){
            if( j == 0){
                Si[i][j] = Si[i-1][j+1] ^ Sortie[i][j] ^ Cin[i][j] ;
                Cout[i][j] = (((Si[i-1][j+1] ^ Sortie[i][j]) & Cin[i][j]) | (Si[i-1][j+1] & Sortie[i][j]));
            }
            else{
                Si[i][j] = Si[i-1][j+1] ^ Sortie[i][j] ^ Cout[i][j-1] ;
                Cout[i][j] = (((Si[i-1][j+1] ^ Sortie[i][j]) & Cout[i][j-1]) | (Si[i-1][j+1] & Sortie[i][j]));
            }
        }
        Si[i][A_bits-1] = Si[i-1][A_bits-1] ^ Sortie[i][A_bits-1] ^ Cout[i][A_bits-2] ;
        Cout[i][A_bits-1] = (((Si[i-1][A_bits-1] ^ Sortie[i][A_bits-1]) & Cout[i][A_bits-2]) | (Si[i-1][A_bits-1] & Sortie[i][A_bits-1]));
    }
    
    for(i = 0 ; i != B_bits ; i ++){
        C[i] = Si[i][0];
    }
    
    for(i = 1 ; i != A_bits ; i ++){
        C[B_bits+i-1] = Si[B_bits-1][i];
    }
    
    C[P_bits] = Cout[B_bits-1][A_bits-1] ^ Cout[B_bits-1][A_bits-2] ^ Si[B_bits-1][A_bits-1];
    //print_binary_tab(C, P_bits);
    /*
     * change radix*/
    if(C[P_bits] == 0){
        for(i = 0 ; i <= P_bits ; i++){
            res = res + C[i] * (1<<i);
        }
    }
    else if(C[P_bits] == 1){
        for(i = P_bits ; i >= 0 ; i--){
            if(C[i] == 0) C[i] = 1;
            else C[i] = 0;
        }
        for(i = P_bits ; i >= 0 ; i--){
            res = res + C[i] * (1<<i);
        }
        res = res + 1;
        res = -res;
        
    }
    
    return res;
    
};
