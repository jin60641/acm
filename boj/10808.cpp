#include<stdio.h>


int a[26];
int main(){
	char s[101];
	scanf("%s",s);
	for( int i = 0; s[i] != '\0'; ++i ){
		++a[s[i] - 97];
	}
	for( int i = 0; i < 26; ++i ){
		printf("%d ",a[i]);
	}
}
