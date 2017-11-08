#include<stdio.h>

int a[26];
int main(){
	char s[1000001];
	scanf("%s",s);
	for( int i = 0; s[i] != '\0'; ++i ){
		if( s[i] >= 'a' && s[i] <= 'z' ){
			++a[s[i]-'a'];
		} else {
			++a[s[i]-'A'];
		}
	}
	int max = -1;
	int max_index = -1;
	for( int i = 0; i < 26; ++i ){
		if( a[i] > max ){
			max = a[i];
			max_index = i;
		}
	}
	int max_cnt = 0;
	for( int i = 0; i < 26; ++i ){
		if( a[i] == max ){
			++max_cnt;
		}
	}
	if( max_cnt != 1 ){
		printf("?\n");
	} else {
		printf("%c\n",max_index+'A');
	}
}

