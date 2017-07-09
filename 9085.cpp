#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int N;
		scanf("%d",&N);
		int tot = 0;
		for( int i = 0; i < N; ++i ){
			int a;
			scanf("%d",&a);
			tot += a;
		}
		printf("%d\n",tot);
	}
}
