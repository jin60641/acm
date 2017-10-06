#include<stdio.h>

int main(){
	int flag = 0;
	for( int i = 1; i <= 5; ++i ){
		char s[11];
		scanf("%s",s);
		int len = 0;
		for( ; s[len] != '\0'; ++len );
		for( int j = 0; j <= len-3; ++j ){
			if( s[j] == 'F' && s[j+1] == 'B' && s[j+2] == 'I' ){
				printf("%d ",i);
				flag = 1;
				break;
			}
		}
	}
	if( flag == 0 ){
		printf("HE GOT AWAY!\n");
	}
	return 0;
}
