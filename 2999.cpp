#include<stdio.h>
#include<string.h>

int main(){
	char s[101];
	scanf("%s",s);
	int N = strlen(s);
	int R,C;
	for( int i = 1; i*i <= N; ++i ){
		if( N%i == 0 ){
			if( i <= N/i ){
				R = i;
				C = N/i;
			} else {
				break;
			}
		}
	}
	for( int i = 0; i < R; ++i ){
		for( int j = 0; j < C; ++j ){
			printf("%c",s[i+j*R]);
		}
	}
	return 0;
}
