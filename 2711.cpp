#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int N;
		scanf("%d",&N);
		char s[100];
		scanf("%s",s);
		for( int i = 0; s[i] != 0; ++i ){
			if( i == N-1 ){
				continue;
			}
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
