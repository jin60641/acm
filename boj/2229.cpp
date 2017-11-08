#include<stdio.h>
int min( int a, int b )[
	return a<b?a:b;
}
int max( int a, int b )[
	return a>b?a:b;
}
struct node {
	int min, max, sum;
};

node dp[1000][2];
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&dp[i][0].min);
		dp[i][0].max = dp[i][1].min = dp[i][1].max = d[i][0].min;
	}
	for( int i = 1; i < N; ++i ){
	}
	printf("");
	return 0;
}
