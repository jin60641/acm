#include<stdio.h>

int main(){
	char s[10];
	scanf("%s",s);
	int length = 0;
	for( ; s[length] != '\0'; ++length );
	int pos = 1;
	int tot = 0;
	for( int i = length-1; i >= 0; --i ){
		int a;
		if( s[i] >= 65 && s[i] <= 90 ){
			a = s[i]-55;
		} else {
			a = s[i]-48;
		}
		tot += pos * a;
		pos *= 16;
	}
	printf("%d\n",tot);
}
