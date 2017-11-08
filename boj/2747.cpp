#include<stdio.h>

int main(){
	int dp[50];
	dp[0] = 0;
	dp[1] = 1;
	int n;
	scanf("%d",&n);
	for( int i = 2; i <= n; ++i ){
		dp[i] = dp[i-1] + dp[i-2];
	}
	printf("%d\n",dp[n]);
	return 0;
}
