#include<stdio.h>
int max( int a, int b ){
	return a>b?a:b;
}
int N, S, M, dp[101][1001];
int main(){
	scanf("%d %d %d",&N,&S,&M);
	dp[0][S] = 1;
	for( int i = 1; i <= N; ++i ){
		int a;
		scanf("%d",&a);
		for( int j = 0; j <= M; ++j ){
			if( dp[i-1][j] == 1 ){
				if( 0 <= j+a && j+a <= M ){
					dp[i][j+a] = 1;
				}
				if( 0 <= j-a && j-a <= M ){
					dp[i][j-a] = 1;
				}
			}
		}
	}
	for( int i = M; i >= 0; --i ){
		if( dp[N][i] == 1 ){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
