#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		char s[101];
		scanf(" %[^\n]",s);
		int flag = 0;
		printf("god");
		for( int i = 0; s[i] != '\0'; ++i ){
			if( flag == 0 ){
				if( s[i] == ' ' ){
					flag = 1;
				}
			} else {
				if( s[i] == ' ' ){
					continue;
				} 
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
