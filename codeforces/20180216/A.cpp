#include<stdio.h>

int main(){
	char s[100001];
	scanf("%s",s);
	int i = 0;
	for(; s[i] != 0; ++i ){
		printf("%c",s[i]);
	}
	for(i-=2; i >= 0; --i ){
		printf("%c",s[i]);
	}
	return 0;
}
