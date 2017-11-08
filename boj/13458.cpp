#include<stdio.h>

long long int A[1000001];
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%lld",&A[i]);
	}
	long long int B,C;
	scanf("%lld %lld",&B,&C);
	long long int cnt = 0;
	for( int i = 0; i < N; ++i ){
		++cnt;
		A[i] -= B;
		if( A[i] <= 0 ){
			continue;
		}
		if( A[i]%C != 0 ){
			++cnt;
		}
		cnt += A[i]/C;
	}
	printf("%lld\n",cnt);
	return 0;
}
