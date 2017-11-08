#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int R;
		char s[30];
		scanf("%d",&R);
		scanf("%s",s);
		for( int i = 0; s[i] != 0; ++i ){
			for( int j = 0; j < R; ++j ){
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
