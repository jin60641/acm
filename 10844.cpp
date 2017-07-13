#include<stdio.h>

long long int dp[101][10];
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 1; i <= 9; ++i ){
		dp[1][i] = 1;
	}
	for( int i = 2; i <= N; ++i ){
		dp[i][0] = dp[i-1][1];
		dp[i][9] = dp[i-1][8];
		for( int j = 1; j <= 8; ++j ){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
		}
	}
	long long int tot = 0;
	for( int i = 0; i <= 9; ++i ){
		tot = (tot+dp[N][i])%1000000000;
	}
	printf("%lld\n",tot);
	return 0;
}
