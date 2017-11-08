#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int a = 0, b = 0;
	char s[101][101];
	for( int i = 0; i < N; ++i ){
		scanf("%s",&s[i]);
		int cnt = 0;
		for( int j = 0; j < N; ++j ){
			if( s[i][j] == '.' ){
				++cnt;
			} else {
				if( cnt >= 2 ){
					++a;
				}
				cnt = 0;
			}
		}
		if( cnt >= 2 ){
			++a;
		}
	}
	for( int i = 0; i < N; ++i ){
		int cnt = 0;
		for( int j = 0; j < N; ++j ){
			if( s[j][i] == '.' ){
				++cnt;
			} else {
				if( cnt >= 2 ){
					++b;
				}
				cnt = 0;
			}
		}
		if( cnt >= 2 ){
			++b;
		}
	}
	printf("%d %d\n",a,b);
	return 0;
}
