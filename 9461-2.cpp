#include<stdio.h>

int main(){
    long long int dp[100];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        for( int i = 5; i < N; ++i ){
            dp[i] = dp[i-1] + dp[i-2] - dp[i-4];
        }
        printf("%lld",dp[N-1]);
    }
}
