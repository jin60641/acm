#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = (i+1); j < N; ++j ){
			printf(" ");
		}
		for( int j = 0; j <= i; ++j ){
			printf("*");
		}
		printf("\n");
	}
	for( int i = 0; i < N-1; ++i ){
		for( int j = 0; j <= i; ++j ){
			printf(" ");
		}
		for( int j = (i+1); j < N; ++j ){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
