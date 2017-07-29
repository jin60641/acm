#include<stdio.h>

int main(){
	int N, cnt = 0;
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		int now = i;
		int r = i%10;
		now /= 10;
		int add = r - now%10;
		++cnt;
		while( now != 0 ){
			if( r - now%10 != add ){
				--cnt;
				break;
			}
			r = now%10;
			now/=10;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
