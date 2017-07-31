#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int k,N;
		scanf("%d %d",&k,&N); 
		long long int dp[10000];
		dp[0] = 1;
		for( int i = 1; i <= N; ++i ){
			dp[i] = 0;
		}
		for( int l = 1; l <= k; ++l ){
			for( int i = N-1; i >= 0; --i ){
				if( dp[i] != 0 ){
					for( int j = 0; j <= l; ++j ){
						if( i+j <= N ){
							++dp[i+j];
						}
					}
				}
			}
		}
		printf("%lld\n",dp[N]);
	}
	return 0;
}
