#include<stdio.h>

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int T[100000];
	long long int left = 1;
	long long int right = 0;
	for( int i = 0; i < N; ++i ){
		scanf("%d",&T[i]);
		if( T[i] > right ){
			right = T[i];
		}
	}
	right *= M;
	while( left <= right ){
		long long int mid = (left+right)/2;
		long long int cnt = 0;
		for( int i = 0; i < N; ++i ){
			cnt += mid/T[i];
		}
		if( cnt >= M ){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	printf("%lld\n", left );
}
