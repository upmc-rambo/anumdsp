//cette fonction permet de changer decimal en binaire

#include "change_to_binary.h"


void  change_to_binary( int a, unsigned char* A ,int len){
         int i, j;
         if (a < 0) {
					           a = -a;
					           for (i = 0 ; a != 0 ; i++){
			                          A[i] = a % 2;
			                          a = a / 2;
		                       }		                      		           
		           
		                       for (j = len-1 ; j >= 0 ; j--){
							          if ( A[j-1] == 0) A[j-1] = 1;
							          else A[j-1] = 0;  
							   }							   
							   
							   if (A[0] == 0){
								          A[0] = 1;
							   }
							   else{
									      A[0] = 0;
									      A[1] = A[1] + 1;
							   }
							   
							   
							   if (A[0] == 0){  
							      for (j = 1 ; j < len ; j++){
								      if (A[j] == 1){								             
								             break;
							          }
							          else{
									      A[j] = 0;
									      A[j+1] = A[j+1] + 1;
								      }
							      }
							  }		  
				   }
		if (a >= 0){
				               for (i = 0 ; a != 0 ; i++){
			                          A[i] = a % 2;
			                          a = a / 2;
		                       }
				   }
  
};

