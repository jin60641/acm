#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int tot = 1;
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		tot += --a;
	}
	printf("%d\n",tot);
}
