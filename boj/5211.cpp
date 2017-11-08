#include<stdio.h>

int check[7];
int main(){
	char s[200];
	scanf("%s",s);
	int bar = -1;
	int i;
	for( i = 0; s[i] != 0; ++i ){
		if( s[i] == '|' ){
			bar = i;
		} else if( i - 1 == bar ){
			++check[s[i]-'A'];
		}
	}
	if( check[0] + check[3] + check[4] == check[2] + check[5] + check[6] ){
		++check[s[i-1]-'A'];
	}
	if( check[0] + check[3] + check[4] > check[2] + check[5] + check[6] ){
		printf("A-minor\n");
	} else {
		printf("C-major\n");
	}
	return 0;
}
