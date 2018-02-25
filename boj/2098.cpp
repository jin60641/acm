#include<stdio.h>
const int max_cost = 1000000;
const int max_N = 16;
const int INF = max_cost * max_N + 1;

int min( int a, int b ){
	return a<b?a:b;
}

int N,a[max_N][max_N], dp[max_N][1<<max_N];

int main(){
	scanf("%d",&N);
	int bit = 1<<N;
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < bit; ++j ){
			dp[i][j] = INF;
		}
	}
	dp[0][1] = 0;
	for( int i = 0; i < bit; ++i ){
		for( int j = 0; j < N; ++j ){
			int tmp = 2;
			for( int k = 1; k < N; ++k ){
				if( !( tmp & i ) && a[j][k] != 0 ){
					dp[k][i+tmp] = min( dp[k][i+tmp], dp[j][i] + a[j][k] );
				}
				tmp = tmp<<1;
			}
		}
	}
	int result = INF;
	for( int i = 1; i < N; ++i ){
		result = min( result, dp[i][bit-1]+a[i][0] );
	}
	printf("%d\n",result);
	return 0;
}
