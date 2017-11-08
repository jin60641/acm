#include<stdio.h>

int max( int a, int b ){
	return a>b?a:b;
}

int dp[10000][3];
int main(){
	int N;
	scanf("%d",&N);
	int a[10000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	dp[0][1] = a[0];
	int result = a[0];
	for( int i = 1; i < N; ++i ){
		dp[i][0] = max( max( dp[i][0], dp[i-1][0] ), max( dp[i-1][1], dp[i-1][2] ) );
		dp[i][1] = max( dp[i][1], dp[i-1][0] + a[i]  );
		dp[i][2] = max( dp[i][2], dp[i-1][1] + a[i]  );
		result = max( max( dp[i][0], result ), max( dp[i][1], dp[i][2] ) );
	}
	printf("%d\n", result );
}
