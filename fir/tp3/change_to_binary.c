//cette fonction permet de changer decimal en binaire

#include "change_to_binary.h"

// a -> A[len]
void  change_to_binary( int a, unsigned char* A ,int len){
    
    int i, j, a_abso = (a > 0) ? a : -a;
    
    for (i = 0 ; a_abso != 0 ; i++){
        A[i] = a_abso % 2;
        a_abso = a_abso / 2;
    }
    
    if (a < 0) {    //traitment of negative integer
        for (j = len-1 ; j >= 0 ; j--){ // 0 -> 1
            if ( A[j-1] == 0)   A[j-1] = 1;
            else                A[j-1] = 0;
        }
        // 1's complement + 1 =  2's complement
        if (A[0] == 0){
            A[0] = 1;
        }else{
            for (i = 0 ; i < len ; i++){
                if (A[i] == 1){
                    break;
                }else{
                    A[i] = 0;
                    A[i+1] = A[i+1] + 1;
                }
            }
        }
    }
    A[len-1] = (a >=- 0) ? 0 : 1;
};
void print_binary_tab(unsigned char * tab, int len ){
    int i;
    for (i = len-1 ; i >= 0; i--){
        printf("%d", tab[i]);
    }
    printf("\n");
};
