#include<stdio.h>

int main(){
	int a;
	char s[101];
	scanf("%d",&a);
	scanf("%s",s);
	int flag = 0;
	for( int i = 0; i < a; ++i ){
		if( flag == 1 ){
			if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ){
			} else {
				printf("%c",s[i]);
				flag = 0;
			}
		} else if( flag == 0 ){
			printf("%c",s[i]);
			if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ){
				flag = 1;
			}
		}
	}
	printf("\n");
	return 0;
}
