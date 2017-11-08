#include<stdio.h>

int main(){
	int now = 1;
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int a,b;
		scanf("%d %d",&a,&b);
		if( a == now ){
			now = b;
		} else if( b == now ){
			now = a;
		}
	}
	printf("%d\n",now);
	return 0;
}
