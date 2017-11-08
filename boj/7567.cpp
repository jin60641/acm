#include<stdio.h>

int main(){
	char s[51];
	int flag = -1;
	int tot = 0;
	scanf("%s",s);
	for( int i = 0; s[i] != '\0'; ++i ){
		if( s[i] == '(' ){
			if( flag == 0 ){
				tot += 5;	
			} else {
				tot += 10;
			}
			flag = 0;
		} else if( s[i] == ')' ){
			if( flag == 1 ){
				tot += 5;
			} else {
				tot += 10;
			}
			flag = 1;
		}
	}
	printf("%d\n",tot);
	return 0;
}
