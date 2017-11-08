#include<stdio.h>

int check[1120];
int main(){
	int p = 0;
	int a[200];
	for( int i = 2; i < 1120; ++i ){
		if( check[i] == 1 ){
			continue;
		}
		a[p++] = i;
		for( int j = i*2; j < 1120; j += i ){
			check[j] = 1;
		}
	}

	int T;
	scanf("%d",&T);
	while( T > 0 ){
		T--;
		int n,m;
		scanf("%d %d",&n,&m);
		int dp[15][1121];
		for( int i = 0; i <= m; ++i ){
			for( int j = 0; j <= n; ++j ){
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for( int i = 0; i < p; ++i ){
			for( int j = m; j >= 0; --j ){
				for( int k = n-1; k >= 0; --k ){
					if( dp[j][k] != 0 && k+a[i] <= n ){
						dp[j+1][k+a[i]] += dp[j][k];
					}
				}
			}
		}
		printf("%d\n",dp[m][n]);
	}
	return 0;
}

