#include<stdio.h>

long long int sum[1001];
int main(){
	long long int N;
	long long int a[1001][1001];
	long long int tot = 0;
	scanf("%lld",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			scanf("%lld",&a[i][j]);
			sum[i] += a[i][j];
		}
		tot += sum[i];
	}
	if( N == 2 ){
		printf("%d %d\n",1,a[0][1]-1);
		return 0;
	}
	tot /= (N-1)*2;
	for( int i = 0; i < N; ++i ){
		printf("%lld ",(sum[i]-tot)/(N-2));
	}
	return 0;
}
