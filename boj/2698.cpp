#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int n,k;
		scanf("%d %d",&n,&k);
		int dp[100][100][2]; // i : 인접비트갯수
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j < n; ++j ){
				dp[i][j][0] = 0;
				dp[i][j][1] = 0;
			}
		}
		dp[0][0][0] = 1;
		dp[0][0][1] = 1;
		
		for( int i = 1 ; i < n; ++i ){
			for( int j = 0; j < i; ++j ){
				dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1];
				dp[i][j][1] += dp[i-1][j][0];
				dp[i][j+1][1] += dp[i-1][j][1];
			}
		}
		printf("%d\n",dp[n-1][k][0]+dp[n-1][k][1]);
	}
	return 0;
}
