#include<stdio.h>

int main(){
	int M,N;
	scanf("%d %d",&N,&M);
	
	for( int i = N; i <= M; ++i ){
		if( i == 1 ){
			continue;
		}
		int a = 0;
		for( int j = 2; j*j <= i; ++j ){
			if( i%j==0 ){
				++a;
			}
		}
		if( a == 0 ){
			printf("%d\n",i);
		}
	}
}
