#include<stdio.h>

int min( int a, int b ){
	return a<b?a:b;
}
int dp[2000000];	

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		dp[N] = -1;
	}
	dp[N] = 0;
	for( int i = N-1; i >= 0; --i ){
		int min1 = dp[i+1]+1;
		int min2 = 1000000;
		if( i*2 <= N ){
			min2 = dp[i*2]+1;
		}
		int min3 = 10000000;
		if( i*3 <= N ){
			min3 = dp[i*3]+1;
		}
		dp[i] = min(min(min1,min2),min3);
	}
	printf("%d",dp[1]);
	return 0;
}
