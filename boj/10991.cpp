#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = N-1; j > i; --j ){
			printf(" ");
		}
		for( int j = 0; j < i*2+1; ++j ){
			if( i%2 ){
				printf("%c",j%2?' ':'*');
			} else {
				printf("%c",j%2?' ':'*');
			}
		}
		printf("\n");
	}
	return 0;
}
