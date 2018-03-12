#include"stdio.h"
 #include"math.h"
 #include"string.h"
#include "fir.h"

int main(){
short i,j,n,k,c,l;
short x[100][100];
short OUT[100]={0};
short RES[100]={0};
double a[100];
short y[100][100];
printf("N:");
scanf("%hd\n",&n);
printf("K:");
scanf("%hd\n",&k);
printf("C:");
scanf("%hd\n",&c);
printf("l:");
scanf("%hd\n",&l);
printf("X:input\n");
for(i=0;i<n;i++){
for(j=k-1;j>=0;j--){
scanf("%hd\n",&a[i][j]);
   };
for(i=0;i<l;i++){
for(j=c-1;j>=0;j--){
scanf("%hd\n",&a[i][j]);
   };
FIR(short *x, short k, short *a, short c, short l, short *y);

for(i=0.i<8+L-1;i++){
for(j=k-1;j>=0;j++){
 printf("%hd:",y[i][j]);
};
printf("\n");
};

}


