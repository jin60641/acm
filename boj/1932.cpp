#include<stdio.h>

int max( int a, int b ){
	return a>b?a:b;
}

int main(){
	int n;
	scanf("%d",&n);
	int a[500][500];
	int dp[500][500];
	for( int i = 0; i < n; ++i ){
		for( int j = 0; j <= i; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	dp[0][0] = a[0][0];
	for( int i = 1; i < n; ++i ){
		for( int j = 0; j <= i; ++j ){
			if( j == 0 ){
				dp[i][j] = dp[i-1][j] + a[i][j];
			} else if( j == i ){
				dp[i][j] = dp[i-1][j-1] + a[i][j];
			} else {
				dp[i][j] = max( dp[i-1][j] + a[i][j], dp[i-1][j-1] + a[i][j] );
			}
		}
	}
	int result = 0;
	for( int j = 0; j < n; ++j ){
		result = max( result, dp[n-1][j] );
	}
	printf("%d\n",result);
}
