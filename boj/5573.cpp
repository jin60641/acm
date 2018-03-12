#include<stdio.h>
int H,M,N, a[1000][1000], dp[1000][1000];
int ff(int i,int j){
	if( i == H || j == M ){
		printf("%d %d\n",i+1,j+1);
		return 0;
	}
	if(a[i][j]){
		ff(i,j+1);
	} else {
		ff(i+1,j);
	}
	return 0;
}

int main(){
	scanf("%d %d %d",&H,&M,&N);
	for( int i = 0; i < H; ++i ){
		for( int j = 0; j < M; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	dp[0][0] = N-1;
	for( int i = 0; i < H; ++i ){
		for( int j = 0; j < M; ++j ){
			if( i ){
				if( dp[i-1][j] % 2 ){
					if( a[i-1][j] ) dp[i][j] += dp[i-1][j]/2;
					else dp[i][j] += dp[i-1][j]/2+1;
				} else dp[i][j] += dp[i-1][j]/2;
			}
			if( j ){
				if( dp[i][j-1] % 2 ){
					if( a[i][j-1] ) dp[i][j] += dp[i][j-1]/2+1;
					else dp[i][j] += dp[i][j-1]/2;
				} else dp[i][j] += dp[i][j-1]/2;
			}
		}
	}
	for( int i = 0; i < H; ++i ){
		for( int j = 0; j < M; ++j ){
			a[i][j] = dp[i][j]%2 ^ a[i][j];
		}
	}
	ff(0,0);
	return 0;
}

