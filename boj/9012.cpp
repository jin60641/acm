#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T-- > 0){
		char s[51];
		scanf("%s",s);	
		int small = 0;
		int big = 0;
		for( int i = 0; s[i] != '\0'; ++i ){
			switch( s[i] ){
				case '(':
					++small;
					break;
				case ')':
					--small;
					break;
			}
			if( small < 0 ){
				break;
			}
		}
		if( small != 0 ){
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}
