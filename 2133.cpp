#include<stdio.h>
int main(){
    int N;
	long long int dp[31];
    scanf("%d",&N);
	for( int i = 0; i <= N; ++i ){
		dp[i] = 0LL;
	}
    dp[0] = 1LL;
    dp[2] = 3LL;
    for( int i = 4; i <= N; i += 2 ){
        if( i%2 == 0 ){
            for( int j = 2; j <= i; j+=2 ){
                dp[i] += (j==2?3LL:2LL)*dp[i-j];
            }
        }
    }
    printf("%lld\n",dp[N]);
    return 0;
}

