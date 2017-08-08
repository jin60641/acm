#include<stdio.h>
#include<vector>
int a[20][300];
int dp[301];
int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	std::vector<int> path[301];
	for( int i = 1; i <= N; ++i ){
		int b;
		scanf("%d",&b);
		for( int j = 0; j < M; ++j ){
			scanf("%d",&a[j][b]);
		}
	}
	for( int i = 1; i <= 300; ++i ){
		dp[i] = -1;
	}
	for( int i = 0; i < M; ++i ){
		for( int j = 300; j >= 0; --j ){
			if( dp[j] != -1 ){
				for( int k = 1; k <= N; ++k ){
					if( j + k <= N ){
						if( dp[j+k] < dp[j] + a[i][k] ){
							path[j+k].clear();
							path[j+k].assign( path[j].begin(), path[j].end() );
							path[j+k].push_back(k);
							dp[j+k] = dp[j] + a[i][k];
						}
					}
				}
			}
			if( path[j].size() != i+1 ){
				path[j].push_back(0);
			}
		}
	}
	int result = 0;
	int index = 0;
	for( int i = 0; i <= N; ++i ){
		if( result < dp[i] ){
			index = i;
			result = dp[i];
		}
	}
	printf("%d\n",result);
	for( int i = 0; i < path[index].size(); ++i ){
		printf("%d ",path[index][i]);
	}
	printf("\n");
	return 0;
}
