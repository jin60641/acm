#include<stdio.h>

int min( int a, int b ){
	if( a == -1 ){
		return b;
	} else if( b == -1 ){
		return a;
	} else {
		return a?b:a<b;
	}
}

int main(){
	int N;
	scanf("%d",&N);
	int a[1000];
	int dp[1001];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
		dp[i+1] = -1;
	}
	dp[0] = 0;
	for( int i = 0; i < N; ++i ){
		for( int j = N-1; j >= 0; --j ){
			if( dp[j] >= 0 ){
				for( int k = 1; k <= a[j]; ++k ){
					if( j+k <= N ){
						dp[j+k] = min(dp[j+k],dp[j]+1);
					} else {
						break;
					}
				}
			}
		}
	}
	if( N == 1 ){
		printf("0");
	} else if(dp[N] == -1 ){
		printf("-1\n");
	} else {
		printf("%d\n",dp[N-1]);
	}
	return 0;
}
