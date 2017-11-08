#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int cnt = 0;
	for( int i = 0; i < N; ++i ){
		char s[101];
		scanf("%s",s);
		int check[30];
		for( int j = 0; j <= 'z'-'a'; ++j ){
			check[j] = 0;
		}
		char flag = s[0];
		check[flag-'a'] = 1;
		++cnt;
		for( int j = 1; s[j] != '\0'; ++j ){
			if( flag != s[j] && check[s[j]-'a'] == 1 ){
				--cnt;
				break;
			}
			flag = s[j];
			check[flag-'a'] = 1;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
