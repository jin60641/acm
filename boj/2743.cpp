#include<stdio.h>

int main(){
	char s[101];
	scanf("%s",s);
	int i;
	for( i = 0; s[i] != '\0'; ++i );
	printf("%d",i);
}
