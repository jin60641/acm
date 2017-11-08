#include<stdio.h>

int A[1010];
int N;
int K;

int getMinIndex(){
	for( int i = 1; i < N; ++i ){
		if( A[i] != 0 ){
			return i;
		}
	}
}

int che(){
	int min = getMinIndex();
	int Amin = A[min];
	for( int i = min; i < N; i += Amin ){
		if( A[i] == 0 ){
			continue;
		}
		K--;
		if( K == 0 ){
			printf("%d\n",A[i]);
			return 0;
		} else {
			A[i] = 0;
		}
	}
	che();
}

int main(){
	scanf("%d %d",&N,&K);
	
	for( int i = 0; i < N; ++i ){
		A[i] = i+1;
	}
	che();
	return 0;
}

