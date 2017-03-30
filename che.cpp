#include<stdio.h>

int A[1010];

int getMinIndex(){
	int i;
	for( int i = 1; i < N; ++i ){
		
	}
}

int che(){
	
}

int main(){
	int N;
	int K;
	scanf("%d %d",&N,&K);
	
	for( int i = 0; i < N; ++i ){
		A[i] = i+1;
	}

	for( int i = 2; i < N; ++i ){
		if( A[i] == 0 ){
			continue;
		}
		for( int j = 2; j*j < N; ++j ){
			if( A[i]%j == 0 ){
				K--;
				if( K == 0 ){
					printf("%d\n",A[i]);
					return 0;
				} else {
					A[i] = 0;
					break;
				}
			}
		}
	}
	for( int i = 0; i < N; ++i ){
		printf("%d ",A[i]);
	}
		printf("\n");

	return 0;
}

