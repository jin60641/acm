#include<stdio.h>

int main(){
	char s[101];
	scanf("%s",s);
	char r[101];
	r[0] = s[0];
	int index = 1;
	for( int i = 1; s[i] != '\0'; ++i ){
		if( s[i] == '-' && s[i+1] != '\0' && s[i+1] != '-' ){
			r[index++] = s[i+1];
		}
	}
	r[index] = '\0';
	printf("%s\n",r);
}
