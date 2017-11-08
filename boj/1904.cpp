#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	long long int dp[1000001];
	dp[0] = 1;
	dp[1] = 1;
	for( int i = 2; i <= N; ++i ){
		dp[i] = (dp[i-1]+dp[i-2])%15746;
	}
	printf("%lld\n",dp[N]);
	return 0;
}
