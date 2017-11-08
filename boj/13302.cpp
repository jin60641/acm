#include<stdio.h>
int min( int a, int b ){
	if( a == -1 ){
		return b;
	} else if( b == -1 ){
		return a;
	} else {
		return a<b?a:b;
	}
}
struct pass {
	int price;
	int coupon;
	int day;
};
const pass p[3] = { { 10000, 0, 1 }, { 25000, 1, 3 }, { 37000, 2, 5 } };
int arr[101];
int dp[101][55];
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for( int i = 0; i <= N; ++i ){
		for( int j = 0; j < 50; ++j ){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for( int i = 0; i < M; ++i ){
		int k;
		scanf("%d",&k);
		arr[k] = 1;
	}
	for( int i = 1; i <= N; ++i ){
		if( arr[i] == 0 ){
			for( int j = 29; j >= 0; --j ){
				if( dp[i-1][j] != -1 ){
					for( int k = 0; k < 3; ++k ){
						for( int m = 0; m < p[k].day; ++m ){
							dp[i+m][j+p[k].coupon] = min( dp[i+m][j+p[k].coupon], dp[i-1][j] + p[k].price );
							if( k == 0 && dp[i-1][j+3] != -1 ){ 
								dp[i][j] = min( dp[i-1][j+3], dp[i][j] );
							}
						}
					}
				}
			}
		} else {
			for( int j = 0; j < 30; ++j ){
				dp[i][j] = min( dp[i][j], dp[i-1][j] );
			}
		}
	}
	int result = -1; 
	for( int i = 0; i < 30; ++i ){
		result = min( result, dp[N][i] );
	}
	printf("%d\n",result );
	return 0;
}
