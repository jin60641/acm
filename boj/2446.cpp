#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < i; ++j ){
			printf(" ");
		}
		for( int j = 0; j < N*2-1-2*i; ++j ){
			printf("*");
		}
		printf("\n");
	}
	for( int i = N-2; i >= 0; --i ){
		for( int j = 0; j < i; ++j ){
			printf(" ");
		}
		for( int j = 0; j < N*2-1-2*i; ++j ){
			printf("*");
		}
		printf("\n");
	}
}
