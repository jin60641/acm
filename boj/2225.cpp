#include<stdio.h>

int N, K, dp[201][201];
int main(){
	scanf("%d %d",&N,&K);
	for( int i = 0; i <= N; ++i ){
		dp[i][0] = 1;
	}
	for( int i = 1; i <= K; ++i ){
		for( int j = N; j >= 0; --j ){
			for( int k = 0; k <= N; ++k ){
				if( j - k >= 0 ){
					dp[j][i] = (dp[j-k][i-1] + dp[j][i])%1000000000;
				} else {
					break;
				}
			}
		}
	}
	printf("%d ",dp[N][K-1]);
	return 0;
}
