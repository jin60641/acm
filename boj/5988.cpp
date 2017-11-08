#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	while( N-- ){
		char s[1000];
		scanf("%s",s);
		int len;
		for( len = 0; s[len] != '\0'; ++len );
		int a = s[len-1]-'0';
		printf(a%2?"odd\n":"even\n");
	}
	return 0;
}
