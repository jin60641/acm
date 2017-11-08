#include<stdio.h>

int main(){
	char s[101];
	scanf("%s",s);
	for( int i = 0; s[i] != 0; ++i ){
		if( s[i] >= 'A' && s[i] <= 'Z' ){
			s[i] += 'a'-'A';
		} else {
			s[i] -= 'a'-'A';
		}
	}
	printf("%s\n",s);
	return 0;
}
