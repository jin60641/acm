#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	char s[1000];
	scanf("%s",&s);
	int tot = 0;
	for( int i = 0 ; i < N; ++i ){
		tot += s[i] - '0';
	}
	printf("%d\n",tot);
	return 0;
}
