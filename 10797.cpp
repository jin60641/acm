#include<stdio.h>

int main(){
	int N;
	int cnt = 0;
	scanf("%d",&N);
	for( int i = 0; i < 5; ++i ){
		int a;
		scanf("%d",&a);
		if( a == N ){
			++cnt;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
