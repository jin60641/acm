#include<stdio.h>

int max( int a, int b ){
	return a>b?a:b;
}

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int result = 0;
		int N;
		scanf("%d",&N);
		int arr[100000][2];
		int dp[100000][2];
		for( int i = 0; i < N; ++i ){
			scanf("%d",&arr[i][0]);
		}
		for( int i = 0; i < N; ++i ){
			scanf("%d",&arr[i][1]);
		}
		if( N == 1 ){
			printf("%d\n",max(arr[0][0],arr[0][1]));
			continue;
		}
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = dp[0][1] + arr[1][0];
		dp[1][1] = dp[0][0] + arr[1][1];
		for( int i = 2; i < N; ++i ){
			int a = dp[i-1][1] + arr[i][0];
			int b = dp[i-1][0] + arr[i][1];
			int c = max( dp[i-2][0], dp[i-2][1] ) + arr[i][0];
			int d = max( dp[i-2][0], dp[i-2][1] ) + arr[i][1];
			dp[i][0] = max( a, c );
			dp[i][1] = max( b, d );
			result = max( max( dp[i][0], dp[i][1] ), result );
		}
		printf("%d\n",result);
	}
}
