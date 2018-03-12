#include"stdio.h"
#include"math.h"
#include"string.h"
void ADD(short * A,short * B,short  cin,short * S,short * cout,short N){
    short i,k,p,m,l,t;
    short pi[100];
    short gi[100];
    short pl=1;
    k= (short)(sqrt(N/2));
    p=N/k;
    S[0]=(A[0]^B[0])^cin;
    pi[0]=A[0]^B[0];
    gi[0]=A[0]&B[0];
    cout[0]=(gi[0]|(pi[0]&cin));
    if((k*k!=N)||(p<4)){
        for(i=1;i<N;i++){
            S[i]=(A[i]^B[i])^cout[i-1];
            pi[i]=A[i]^B[i];
            gi[i]=A[i]&B[i];
            cout[i]=(gi[i]|(pi[i]&cout[i-1]));
            
        }
        
    }
    else{
        for(i=1;i<k;i++){
            pi[i]=A[i]^B[i];
            gi[i]=A[i]&B[i];
            S[i]=A[i]^B[i]^cout[i-1];
            cout[i]=gi[i]|(pi[i]&cout[i-1]);
        };
        
        for(l=0;l<(p-2);l++){
            
            for(t=(l+1)*k;t<(l+2)*k;t++){
                pi[t]=A[t]^B[t];
                
                pl=pl&pi[t];
            };
            if(pl==1) {
                for(t=(l+1)*k;t<(l+2)*k;t++){
                    cout[t]=cout[(l+1)*k-1];
                };
            };
            if(pl==0){
                for(t=(l+1)*k;t<(l+2)*k;t++){
                    gi[t]=A[t]&B[t];
                    cout[t]=gi[t]|(pi[t]&cout[t-1]);
                };
            };
            for(t=(l+1)*k;t<(l+2)*k;t++){
                S[t]=A[t]^B[t]^cout[t-1];
            };
            
        };
        
        for(m=N-k;m<N;m++){
            pi[m]=A[m]^B[m];
            gi[m]=A[m]&B[m];
            S[m]=A[m]^B[m]^cout[m-1];
            cout[m]=gi[m]|(pi[m]&cout[m-1]);
        };
    };
};
int main()
{
    
    short n,CIN;
    short i=0;
    short a[100];
    short b[100];
    short COUT[100];
    short s[100];
    void ADD(short * A,short * B,short  cin,short * S,short * cout,short N);
    printf("N:");
    scanf("%hd",&n);
    printf("cin:");
    scanf("%hd",&CIN);
    printf("A:\n");
    for(i=n-1;i>=0;i--){
        scanf("%hd",&a[i]);
    };
    printf("B:\n");
    for(i=n-1;i>=0;i--){
        scanf("%hd",&b[i]);
    };
    ADD(a,b,CIN,s,COUT,n);
    printf("s:\n");
    for(i=n-1;i>=0;i--){
        
        printf("%hd",s[i]);
    };
    printf("\n");
    printf("cout:\n");
    for(i=n-1;i>=0;i--){
        
        printf("%hd",COUT[i]);
    };
    printf("\n");
};


