#include<stdio.h>
char c[1000001];
int main(){
	scanf("%[^\n]",c);
	int flag = 0;
	int cnt = 0;
	for( int i = 0; c[i] != '\0'; ++i ){
		if( c[i] != ' ' ){
			if( flag == 0 ){
				flag = 1;
				++cnt;
			}
		} else {
			flag = 0;
		}
	}
	printf("%d\n",cnt);
}
