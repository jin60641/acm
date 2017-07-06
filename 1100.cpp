#include<stdio.h>

int main(){
	int n = 8;
	int cnt = 0;
	for( int i = 0; i < 8; ++i ){
		char s[10];
		scanf("%s",s);
		for( int j = 0; j < 8; ++j ){
			if( ( i%2 == 0 && j%2 == 0 ) || ( i%2 == 1 && j%2 == 1 ) ){
				if( s[j] == 'F' ){
					++cnt;
				}
			}
		}
	}
	printf("%d\n",cnt);
}
