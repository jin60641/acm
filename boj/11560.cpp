#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int k,N;
		scanf("%d %d",&k,&N); 
		long long int dp[10000];
		long long int tmp[10000];
		dp[0] = 1;
		dp[1] = 1;
		for( int i = 2; i <= N; ++i ){
			dp[i] = 0;
		}
		for( int l = 2; l <= k; ++l ){
			for( int i = 0; i <= N; ++i ){
				tmp[i] = 0;
			}
			for( int i = 0; dp[i] != 0; ++i ){
				for( int j = 0; j <= l; ++j ){
					if( i+j <= N ){
						tmp[i+j] += dp[i];
					}
				}
			}
			for( int i = 0; tmp[i] != 0; ++i ){
				dp[i] = tmp[i];
			}
		}
		printf("%lld\n",dp[N]);
	}
	return 0;
}
