#include<stdio.h>

int main(){
	int T ;
	scanf("%d",&T);
	while(T--){
		char s[100];
		scanf("%s",s);
		int tot = 0;
		int add = 0;
		for( int i = 0; s[i] != '\0'; ++i ){
			if( s[i] == 'O' ){
				tot += ++add;
			} else {
				add = 0;
			}
		}
		printf("%d\n",tot);
	}
}
