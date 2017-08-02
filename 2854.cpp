#include<stdio.h>
long long int dp[100001][2];
long long int a[100001];
long long int b[100001];

long long int mod( long long int num ){
	return num%1000000007LL;
}
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		scanf("%lld",&a[i]);
	}
	for( int i = 1; i <= N-1; ++i ){
		scanf("%lld",&b[i]);
	}
	dp[1][0] = a[1];
	dp[1][1] = b[1];
	for( int i = 2; i <= N; ++i ){
		dp[i][0] = mod(dp[i-1][0] * a[i]) + mod(dp[i-1][0] * b[i-1]) + mod(dp[i-1][1] * a[i]) + mod(dp[i-1][1] * (b[i-1]-1));
		dp[i][1] = mod(dp[i-1][0] * b[i]) + mod(dp[i-1][1] * b[i]);
	}
	printf("%lld\n",mod(dp[N][0]+dp[N][1]));
	return 0;
}
