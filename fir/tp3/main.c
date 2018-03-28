//
//  main.c
//  dsp_fir
//
//  Created by Jiang hongbo on 21/02/2018.
//  Copyright © 2018 Jiang Hongbo. All rights reserved.
//

#include <stdio.h>
#include "change_to_binary.h"
#include "mult.h"
#include "fulladder.h"

#define B 4

static unsigned char A[100][64];//MSB on the right
static unsigned char X[100][64];
static unsigned char Y[100][128];

/*  calculate y[n]
 *  y[n] = x[0]*a[n] + x[1]*a[n-1] + ... + x[n]* a [0]
 */

void fir_filt(unsigned char** x,int x_len, unsigned char** y,int y_len ,int Bit){
    
    int i,yn;
    int cin = 0, cout = 0;
    unsigned char RES[100]={0};
    memset(RES, 0, sizeof(unsigned char)*100);
    unsigned char trans[100][100];
    
    printf("**********   OUTPUT  Y  ***********\n");
    
    for(yn=0;yn<y_len;yn++){
        memset(trans, 0, sizeof(unsigned char)*10000);//reset
        
        for(i=0;i<=yn;i++){
            mult((unsigned char*)A[i],Bit,(unsigned char*)X[yn-i],Bit,(unsigned char*)trans[i]);//---------------------trans[i]=a[i]*x[n-i]
        }
        
        for (i = 0; i<=yn;i++)
            NBITS_ADDER((unsigned char*)Y[yn], (unsigned char*)&trans[i],  cin, (unsigned char*)Y[yn],  cout, 2*Bit);//OUT+=trans[n];
        
        printf("Y[%d]=",yn);
        print_binary_tab(Y[yn], 2*Bit-1);
        
    }
    
}

int main(int argc, const char * argv[]) {
    int i,l,b;
    
    printf("RIF:\n");
    printf("Enter Bits of X : ");
    scanf("%d",&b);
    printf("Enter Length of X : ");
    scanf("%d",&l);
    
    
    printf("**********ENTER VALUE X:***********\n");
    int x[l];
    for (i=0;i<l;i++){
        printf("x[%d]=",i);
        scanf("%d",&x[i]);
        change_to_binary(x[i], X[i], b);
    }
    for (i=l;i<l+2;i++){
        change_to_binary(0, X[i], b);
    }
    //******check enter value *******//
    /*printf("X[%d][%d]=\n",l,b);
     for (i=0;i<l+4;i++){
     print_binary_tab(X[i], b);
     }*/
    printf("**********ENTER VALUE A:***********\n");
    int a[3];
    for (i=0;i<3;i++){
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
        change_to_binary(a[i], A[i], b);
    }
    for (i=3;i<l+4;i++){
        change_to_binary(0, A[i], b);
    }
    //******check enter value *******//
    /*printf("A[%d][%d]=\n",l,b);
     for (i=0;i<l+4;i++){
     print_binary_tab(A[i], b);
     }*/
    
    fir_filt((unsigned char**)X ,l, (unsigned char**)Y,l+2, b);
    
    return 0;
}

















