#include<stdio.h>
int min( int a, int b ){
	if( a == -1 ){
		return b;
	}
	if( b == -1 ){
		return a;
	}
	return a<b?a:b;
}
int max( int a, int b ){
	return a>b?a:b;
}
int main(){
	int dp[100000][3];
	int a[100000][3];
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	}
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];
	for( int i = 1; i < N; ++i ){
		dp[i][0] = -1;
		dp[i][1] = -1;
		dp[i][2] = -1;
	}
	for( int i = 1; i < N; ++i ){
		dp[i][0] = max( dp[i-1][0], dp[i-1][1] ) + a[i][0];
		dp[i][1] = max( dp[i-1][2], max( dp[i-1][0], dp[i-1][1] ) )+ a[i][1];
		dp[i][2] = max( dp[i-1][2], dp[i-1][1] ) + a[i][2];
	}
	printf("%d ",max( max(dp[N-1][0],dp[N-1][1]),dp[N-1][2] ) );
	for( int i = 1; i < N; ++i ){
		dp[i][0] = -1;
		dp[i][1] = -1;
		dp[i][2] = -1;
	}
	for( int i = 1; i < N; ++i ){
		dp[i][0] = min( dp[i-1][0], dp[i-1][1] ) + a[i][0];
		dp[i][1] = min( dp[i-1][2], min( dp[i-1][0], dp[i-1][1] ) )+ a[i][1];
		dp[i][2] = min( dp[i-1][2], dp[i-1][1] ) + a[i][2];
	}
	printf("%d",min( min(dp[N-1][0],dp[N-1][1]),dp[N-1][2] ) );
	return 0;
}
