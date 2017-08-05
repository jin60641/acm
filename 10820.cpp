#include<stdio.h>

int main(){
	char s[101];
	while( scanf("%[^\n]s",s) != EOF ){
		getchar();
		int cnt[4] = { 0, 0, 0, 0 };
		for( int i = 0; s[i] != 0; ++i ){
			if( s[i] == ' ' ){
				++cnt[3];
			} else if( s[i] >= 'A' && s[i] <= 'Z' ){
				++cnt[1];
			} else if( s[i] >= 'a' && s[i] <= 'z' ){
				++cnt[0];
			} else {
				++cnt[2];
			}
		}
		for( int i = 0; i < 4; ++i ){
			printf("%d ",cnt[i]);
		}
		printf("\n");
	}
	return 0;
}
