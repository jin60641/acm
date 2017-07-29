#include<stdio.h>

int main(){
	char s[101];
	while( scanf("%[^\n]s",s) != EOF ){
		for( int i = 0; s[i] != '\0'; ++i ){
			printf("%c",s[i]);
		}
		printf("\n");
		s[0] = '\0';
		getchar();
	}
	return 0;
}
