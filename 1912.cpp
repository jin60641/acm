#include<stdio.h>

long long int max(long long int a,long long int b){
    return a>b?a:b;
}
int main(){
    int N;
    scanf("%d",&N);
    long long int dp[100001];
    dp[0] = 0;
    int min_index = 0;
    int max_index = 0;
    int result = -1101;
    long long int r = 0;
    for( int i = 0; i < N; ++i ){
        int a;
        scanf("%d",&a);
        dp[i+1] = dp[i] + a;
        result = max(result,a);

        if( dp[min_index] > dp[i+1] ){
            min_index = i+1;
            max_index = min_index;
            r = max(r,dp[max_index]-dp[min_index]);
        } else if( dp[max_index] < dp[i+1] ){
            max_index = i+1;
            r = max(r,dp[max_index]-dp[min_index]);
        }
    }
	if( max_index == min_index && min_index == N && result < 0 ){
		printf("%d",result);
	} else {
	    printf("%lld\n",r);
	}
    return 0;
}

