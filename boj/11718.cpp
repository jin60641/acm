#include<stdio.h>

int main(){
	char s[101];
	while( scanf(" %[^\n]s",s) != EOF ){
		printf("%s\n",s);
	}
	return 0;
}
