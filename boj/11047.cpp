#include<stdio.h>

int main(){
	long long int N,K;
	long long int a[1000000];
	scanf("%d %d",&N,&K);
	long long int cnt = 0;
	for( int i = 0; i < N; ++ i ){
		scanf("%d",&a[i]);
	}
	for( int i = N-1; i >= 0; --i ){
		if( a[i] <= K ){
			long long int n = K/a[i];
			K -= n*a[i];
			cnt += n;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}
