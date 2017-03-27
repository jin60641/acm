#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	if( N == 1 ){
		printf("**\n");
		return 0;
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			if( j <= i ){
				printf("*");
			} else {
				printf(" ");
			}
		}
		for( int j = N-1; j >= 0; --j ){
			if( j <= i ){
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for( int i = N-2; i >= 0; --i ){
		for( int j = 0; j < N; ++j ){
			if( j <= i ){
				printf("*");
			} else {
				printf(" ");
			}
		}
		for( int j = N-1; j >= 0; --j ){
			if( j <= i ){
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
