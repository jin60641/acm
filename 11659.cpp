#include<stdio.h>
int dp[100001];
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for( int i = 1; i <= N; ++i ){
		scanf("%d",&dp[i]);
		dp[i] += dp[i-1];
	}
	while( M-- ){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",dp[r]-dp[l-1]);
	}
	return 0;
}
