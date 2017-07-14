#include<stdio.h>

char s[600][600];

int cnt[5];

int f(int y, int x){
	int tmp = 0;
	for( int i = y; i < y+4; ++i ){
		for( int j = x; j < x+4; ++j ){
			if( s[i][j] == '*' ){
				++tmp;
			}
		}
	}
	++cnt[tmp/4];
	return 0;
}

int main(){
	int M,N;
	scanf("%d %d",&M,&N);
	for( int i = 0; i < (M*4)+(M+1); ++i ){
		scanf("%s",s[i]);
	}
	for( int i = 1; i < (M*4)+(M+1); i+=5 ){
		for( int j = 1; s[i][j] != 0; j+=5 ){
			f(i,j);
		}
	}
	for( int i = 0; i < 5; ++i ){
		printf("%d ",cnt[i]);
	}
	return 0;
}
