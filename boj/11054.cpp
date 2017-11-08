#include<stdio.h>
int max(int a, int b){
	return a>b?a:b;
}
int main(){
	int N,a[1000],dp[1000][2];
	scanf("%d", &N);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
		dp[i][0] = 1;
		dp[i][1] = 1;
	}
	for( int i = 1; i < N; ++i ){
		for( int j = 0; j < i; ++j ){
			if( a[j] < a[i] ){
				dp[i][0] = max( dp[i][0], dp[j][0]+1 );
			} else if( a[j] > a[i] ){
				dp[i][1] = max( max( dp[i][1], dp[j][0]+1 ), dp[j][1]+1 );
			}
		}
	}
	int result = 0;
	for( int i = 0; i < N; ++i ){
		result = max( max( result, dp[i][0] ), dp[i][1] );
	}
	printf("%d\n",result);
	return 0;
}
