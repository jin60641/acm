#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	long long int dp[10];
	for( int i = 0; i <= 9; ++i ){
		dp[i] = 1;
	}
	for( int i = 2; i <= N; ++i ){
		for( int j = 1; j <= 9; ++j ){
			dp[j] = (dp[j] + dp[j-1])%10007;
		}
	}
	long long int tot = 0;
	for( int i = 0; i <= 9; ++i ){
		tot = (tot + dp[i])%10007;
	}
	printf("%lld\n",tot);
	return 0;
}
