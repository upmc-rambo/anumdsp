//#include "fir.h"
#include"stdio.h"
#include"math.h"
#include"string.h"


/**ADDITION**/
void ADDITION(short * A,short * B,short  cin,short * S,short * cout,short N){
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
}


/**MULTIPLICATION**/
void MULTBOOTH(short * A,short * B,short  NB_BITS_A,short NB_BITS_B,short * S){
    /**MUTIPLEX**/
    short i,j,ib,ohlala,id;
    short ADD=0;
    short SUB=0;
    short CIN=0;
    short RES[NB_BITS_A+NB_BITS_B-1];
    short MUX[NB_BITS_A+NB_BITS_B-1];
    short COUT[NB_BITS_A+NB_BITS_B-1];
    short OUT [NB_BITS_A+NB_BITS_B-1];
    short MUXOUT[NB_BITS_A];
    short PLUS[NB_BITS_A];
    short C[NB_BITS_A];
    short MUXTRANS[NB_BITS_A];
    if(B[0]==1){
        ADD=0;
        SUB=1;
    }
    else{
        ADD=0;
        SUB=0;
    }
    for(i=0;i<NB_BITS_A;i++){
        MUX[i]=ADD*A[i]+SUB*(1^A[i]);
    };
    for(i=NB_BITS_A;i<NB_BITS_A+NB_BITS_B-1;i++){  /*extention de signe*/
        MUX[i]=MUX[NB_BITS_A-1];
    };
    for(i=0;i<NB_BITS_A+NB_BITS_B-1;i++){
        RES[i]=0;
    };
    
    ADDITION (MUX,RES,SUB,OUT,COUT,(NB_BITS_A+NB_BITS_B-1));/*CIN=SUB;*/
    
    
    
    for(ohlala=1;ohlala<NB_BITS_B;ohlala++){
        id=ohlala;
        ADD=0;
        SUB=0;
        if(B[id]==0 && B[id-1]==1){
            ADD=1;
            SUB=0;
        };
        if(B[id]==1 && B[id-1]==0){
            ADD=0;
            SUB=1;
        };
        for(i=0;i<NB_BITS_A+NB_BITS_B-1;i++){
            MUX[i]=0;
        };
        for(j=0;j<NB_BITS_A;j++){
            MUX[j]=ADD*A[j]+SUB*(1^A[j]);
        };
        for(i=0;i<NB_BITS_A;i++){
            C[i]=0;
        };
        for(i=0;i<NB_BITS_A;i++){
            MUXTRANS[i]=MUX[i];
        };
        for(i=0;i<NB_BITS_A;i++){
            PLUS[i]=0;
        };
        ADDITION (MUXTRANS,PLUS,SUB,MUXOUT,C,NB_BITS_A);
        for(i=0;i<NB_BITS_A;i++){
            MUX[i]=MUXOUT[i];
        };
        for(i=NB_BITS_A;i<NB_BITS_A+NB_BITS_B-1;i++){  /*extention de signe*/
            MUX[i]=MUX[NB_BITS_A-1];
        };
        /*decalage*/
        for(j=0;j<ohlala;j++){
            for(i=NB_BITS_A+NB_BITS_B-2;i>0;i--){
                MUX[i]=MUX[i-1];
            };
            MUX[0]=0;
        };
        for(i=0;i<(NB_BITS_A+NB_BITS_B-1);i++){
            RES[i]=OUT[i];
        };
        
        for(i=0;i<(NB_BITS_A+NB_BITS_B-1);i++){
            OUT[i]=0;
        };
        for(i=0;i<(NB_BITS_A+NB_BITS_B-1);i++){
            COUT[i]=0;
        };
        
        
        ADDITION (MUX,RES,CIN,OUT,COUT,(NB_BITS_A+NB_BITS_B-1));
        
    };
    
    for(i=0;i<(NB_BITS_A+NB_BITS_B-1);i++){
        S[i]=OUT[i];
    };
    
    if (COUT[NB_BITS_A+NB_BITS_B-3]^COUT[NB_BITS_A+NB_BITS_B-2]){
        S[NB_BITS_A+NB_BITS_B-1]=0;
    }
    else{
        S[NB_BITS_A+NB_BITS_B-1]=S[NB_BITS_A+NB_BITS_B-2];
    };
    
}
/**FILTRE**/
void FIR(short *X, short K, short *A, short C, short L, short **Y){
    short i,j,yn;
    short cin=0;
    short COUNT[100]={0};
    short OUT[100]={0};
    short RES[100]={0};
    short trans[100][100];
    short **b;
    //for(i=0;i<L;i++){
    //A[i]<<(C-1);
    //};
    for(yn=0;yn<8+L-1;yn++){
        memset(trans, 0, sizeof(short) * 100 * 100);
        if(yn<L-1){
            for(i=0;i<=yn;i++){
                MULTBOOTH(&A[i],&X[yn-i],C,K,&trans[i]);
            };
        }
        else if(yn<4){
            for(i=0;i<L;i++){
                MULTBOOTH(&A[i],&X[yn-i],C,K,&trans[i]);
            };
        }
        else if(yn<(4+L-1)){
            for(i=0;i<(L-(yn-7));i++){
                MULTBOOTH(&A[yn-7],&X[yn-i],C,K,&trans[i]);
            };
        };
        for(i=0;i<L;i++){
            for(i=0;i<(K+C+ln(L)/ln(2));i++){
                RES[i]=OUT[i];
            };
            
            for(i=0;i<(K+C+ln(L)/ln(2));i++){
                OUT[i]=0;
            };
            for(i=0;i<(K+C+ln(L)/ln(2));i++){
                COUNT[i]=0;
            };
            
            
            ADDITION (&trans[i],RES,cin,OUT,COUNT,K+C+ln(L)/ln(2));
            
        };
        for(i=0;i<(K+C+(short)(ln(L)/ln(2)));i++){
            Y[yn][i]=OUT[i];
        };
        
        if ((Y[(K+C+ln(L)/ln(2))-1])^(COUNT[(K+C+ln(L)/ln(2))-2]) ){
            Y[(K+C+ln(L)/ln(2))-1]=0;
        }
        else{
            Y[yn][(K+C+ln(L)/ln(2))-1]=Y[yn][(K+C+ln(L)/ln(2))-2];
        };
    };
    
    
}


int main(){
    short i,j,n,k,c,l;
    short x[100][100];
    short OUT[100]={0};
    short RES[100]={0};
    double a[100][100];
    short y[100][100];
    //printf("N:");
    //scanf("%hd\n",&n);
    void FIR(short *X, short K, short *A, short C, short L, short **Y);
    printf("K:");
    scanf("%hd\n",&k);
    printf("C:");
    scanf("%hd\n",&c);
    printf("l:");
    scanf("%hd\n",&l);
    printf("X:input\n");
    for(i=0;i<8;i++){
        for(j=k-1;j>=0;j--){
            scanf("%hd\n",&x[i][j]);
        };
    };
    for(i=0;i<l;i++){
        for(j=c-1;j>=0;j--){
            scanf("%hd\n",&a[i][j]);
        };
    };
    
    FIR(x, k, a, c, l, y);
    
    for(i=0;i<(8+l-1);i++){
        for(j=k-1;j>=0;j++){
            printf("%hd:",y[i][j]);
        };
        printf("\n");
    };
    return 0;
}


