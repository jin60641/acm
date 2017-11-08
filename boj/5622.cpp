#include<stdio.h>

int main(){
	int a[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
	char s[100];
	scanf("%s",s);
	int tot = 0;
	for( int i = 0; s[i] != 0; ++i ){
		tot += a[s[i]-'A'] + 1;
	}
	printf("%d",tot);
	return 0;
}
