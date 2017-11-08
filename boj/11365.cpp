#include<stdio.h>
#include<string.h>

int main(){
	while( true ){
		char s[10000001];
		scanf(" %[^\n]",s);
		int len = strlen(s);
		if( strcmp( "END", s ) == 0 ){
			return 0;
		}
		for( int i = len-1; i >= 0; --i ){
			printf("%c",s[i]);
		}
		printf("\n");
	}
}
