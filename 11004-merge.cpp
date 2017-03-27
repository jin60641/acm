#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int N, K; 
int A[5000001]; 

int *swap(int[], int[], int, int); 

int* cut(int left,int right){ 
	int mid = (left+right)/2;
	if( left == right ){       
		int *B = (int *)malloc(sizeof(int));    
		*B = A[right];
		return B;
	} else {                   
		return swap( cut(left,mid), cut(mid+1,right), left, right );  
	}
}

int* swap(int C[],int D[],int left,int right){
	if( left == right ){ 
		return A+left;
	}
	int mid = (left+right)/2;
	int Csize = mid-left + 1;
	int Dsize = right-(mid+1) + 1;

	if( Csize >= K ){
		for( int i = 0; i < Dsize; ++i ){
			if( D[i] < C[3] ){
				for( int j = 0; j < 4; ++j){
					if( D[i] < C[j] ){
						for( int k = 2; k >= j; --k ){
							C[k+1] = C[k];
						}
						C[j] = D[i];
						break;
					}
				}
			} else {
				break;
			}
		}
	} 

	int *B;
	B = (int *)malloc(sizeof(int)*(Csize+Dsize)); 
	int i = 0;								 
	int j = 0; 								
	int a, b;  								
	while( i < Csize || j < Dsize ){      
		if( j == Dsize ){               
			a = C[i];
			B[i+j] = a;
			++i;
		} else if( i == Csize ){		
			b = D[j];
			B[i+j] = b;
			++j;
		} else {						
			a = C[i];
			b = D[j];
			if( a < b ){
				B[i+j] = a;
				++i;
			} else if( b < a ){			
				B[i+j] = b;
				++j;
			}
		}
	}
	free(C); free(D); 		
	return B;				 
}

int main(){
	scanf("%d",&N);
	scanf("%d",&K);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	
    int *k = cut(0,N-1);
    for( int i = 0; i < 4; ++i ){
        printf("%d ",k[i]);
    }
    printf("\n%d\n",k[K-1]);
	return 0;
}
