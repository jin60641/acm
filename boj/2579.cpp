#include<stdio.h>

int max( int a, int b ){
	return a>b?a:b;
}

int dp[300][2];
int main(){
	int N;
	scanf("%d",&N);
	int a[300];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	if( N == 1 ){
		printf("%d\n",a[0]);
		return 0;
	}
	dp[0][0] = a[0];
	dp[1][0] = a[1];
	dp[1][1] = a[0]+a[1];
	for( int i = 2; i < N; ++i ){
		if( i+1 == N ){
			dp[i][0] = max( dp[i][0], max( dp[i-2][0] + a[i], dp[i-2][1] + a[i] ) );
		} else {
			dp[i][0] = max( dp[i][0], max( dp[i-2][0] + a[i], dp[i-2][1] + a[i] ) );
		}
		dp[i][1] = max( dp[i][1], dp[i-1][0] + a[i] );
	}
	printf("%d\n", max( dp[N-1][1], dp[N-1][0] ) );
}
