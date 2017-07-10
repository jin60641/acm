#include<stdio.h>

int main(){
	char s[333335];
	scanf("%s",s);
	int length = 0;
	for( ; s[length] != '\0'; ++length );
	long long int pos = 1;
	long long int tot = 0;
	for( int i = length-1; i >= 0; --i ){
		int a = s[i]-48;
		tot += pos * a;
		pos *= 8;
	}
	int 
	for( int i = 0; tot>0; ++i )[
		
	}
}
