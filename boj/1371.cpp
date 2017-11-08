#include<stdio.h>

int cnt[26];
int main(){
	char s[5001];
	int max = 0;
	while( scanf("%s[^\n]",s) != EOF ){
		for( int i = 0; s[i] != '\0'; ++i ){
			if( 'a' <= s[i] && s[i] <= 'z' ){
				++cnt[s[i]-'a'];
				max = cnt[s[i]-'a']>max?cnt[s[i]-'a']:max;
			}
		}
	}
	for( int i = 0; i < 26; ++i ){
		printf("%c",cnt[i]==max?i+'a':'\0');
	}
	return 0;
}
