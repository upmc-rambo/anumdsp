#include"stdio.h"
void main() {
int i,j;
int S[5];
//int TRANS[5];
/*for(i=4;i>0;i--){
       TRANS[i]=S[i];
        };
        for(i=4;i>0;i--){
            S[i]=TRANS[i-1];
        };
S[0]=0;*/
printf("IN:\n");
for(i=4;i>=0;i--){
scanf("%d\n",&S[i]);
   };
for(j=3;j>0;j--){
for(i=4;i>0;i--){
	S[i]=S[i-1];
    };
S[0]=0;
};
printf("S\n");
for(i=4;i>=0;i--){
    printf("%d\n",S[i]);
};
system("pause");
};
