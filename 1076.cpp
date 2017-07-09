#include<stdio.h>
#include<string.h>

int f(){
	char s[10];
	scanf("%s",s);
	char c[10][10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	for( int i = 0; i < 10; ++i ){
		if( !strcmp( c[i], s ) ){
			return i;
		}
	}
}

int main(){
	int tot = f()*10+f();
	int cnt = f();
	printf("%d",tot);
	if( tot > 0 ){
		for( int i = 0; i < cnt; ++i ){
			printf("0");
		}
	}
	printf("\n");
	return 0;
}
