#include<stdio.h>

int main(){
	int N,M,sum = 0, left = 0, a[10001], cnt = 0;
	scanf("%d %d",&N,&M);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
		sum += a[i];
		while( sum > M ){
			sum -= a[left];
			++left;
		}
		if( sum == M ){
			++cnt;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
