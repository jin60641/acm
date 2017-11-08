#include<stdio.h>
#include<algorithm>

int main(){
	int A[10000];
	int N,X;
	scanf("%d %d",&N,&X);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);	
	}
	for( int i = 0; i < N; ++i ){
		if( A[i] < X ){
			printf("%d ",A[i]);	
		}
	}

	return 0;
}
