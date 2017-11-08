#include<stdio.h>

long long int min(long long int a, long long int b){
	return a<b?a:b;
}

long long int get(long int a,long long int b){
	if( a < b ){
		return (b-a)*(b-a);
	} else {
		return (a-b)*(a-b);
	}
}

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int t = 0;
	while( t < T ){
		++t;
		int H,W;
		int arr1[100][100];
		int arr2[100][100];
		scanf("%d %d",&H,&W);
		for(int i = 0; i < H; ++i ){
			for(int j = 0; j < W; ++j ){
				scanf("%d",&arr1[i][j]);
			}
		}
		for(int i = 0; i < H; ++i ){
			for(int j = 0; j < W; ++j ){
				scanf("%d",&arr2[i][j]);
			}
		}
		int width = 1;
		long long int result = 3000000000;
		while( width <= W ){
			long long int dp[101][100];
			for( int i = 0; i <= H; ++i ){
				for( int j = 0; j < width; ++j ){
					if( i == 0 ){
						dp[0][j] = 0;
						continue;
					}
					if( width == 1 ){
						long long int a = get(arr1[i-1][W-width+j],arr2[i-1][j]);
						dp[i][j] = dp[i-1][j] + a;
					} else if( j == 0 ){
						long long int a = get(arr1[i-1][W-width+j],arr2[i-1][j]);
						long long int b = get(arr1[i-1][W-width+j+1],arr2[i-1][j+1]);
						dp[i][j] = min(dp[i-1][0]+a,dp[i-1][1]+b);
					} else if( j+1 == width ){
						long long int a = get(arr1[i-1][W-width+j],arr2[i-1][j]);
						long long int b = get(arr1[i-1][W-width+j-1],arr2[i-1][j-1]);
						dp[i][j] = min(dp[i-1][j]+a,dp[i-1][j-1]+b);
					} else {
						long long int a = get(arr1[i-1][W-width+j],arr2[i-1][j]);
						long long int b = get(arr1[i-1][W-width+j-1],arr2[i-1][j-1]);
						long long int c = get(arr1[i-1][W-width+j+1],arr2[i-1][j+1]);
						dp[i][j] = min(dp[i-1][j-1]+b,dp[i-1][j]+a);
						dp[i][j] = min(dp[i-1][j+1]+c,dp[i][j]);
					}
					if( i == H ){
						result = min(result,dp[i][j]);
					}
				}
			}
			width++;
		}
		printf("Case #%d\n",t);
		printf("%d\n",result);
	}
	return 0;
}
