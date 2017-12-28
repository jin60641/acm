#include<stdio.h>
#include<vector>
#include<queue>
const int MAX_N = 500;

struct pair {
	int y,x;
};
int max(int a, int b){
	return a>b?a:b;
}
std::vector<pair> v[501][501];
int arr[MAX_N+2][MAX_N+2], in[MAX_N+1][MAX_N+1], dp[MAX_N+2][MAX_N+2], result = 0;
pair d[2] = { { -1, 0 }, { 0, -1 } };
std::queue<pair> q;

int f(){
	pair now = q.front();
	int y = now.y, x = now.x;
	for( int i = 0; i < v[y][x].size(); ++i ){
		int ny = v[y][x][i].y, nx = v[y][x][i].x;
		if( --in[ny][nx] == 0 ){
			q.push({ ny, nx });
		}
		dp[ny][nx] = max( dp[ny][nx], dp[y][x]+1 );
		result = max( result, dp[ny][nx] );
	}
	q.pop();
}

int main(){
	int n;
	int K = 0;
	scanf("%d",&n);
	for( int i = 1; i <= n; ++i ){
		for( int j = 1; j <= n; ++j ){
			scanf("%d",&arr[i][j]);
			for( int k = 0; k < 2; ++k ){
				pair p = { i+d[k].y, j+d[k].x };
				if( arr[p.y][p.x] == 0 ){
					continue;
				} else if( arr[i][j] < arr[p.y][p.x] ){
					v[i][j].push_back(p);
					++in[p.y][p.x];
				} else if( arr[i][j] > arr[p.y][p.x] ){
					v[p.y][p.x].push_back({i,j});
					++in[i][j];
				}
			}
		}
	}
	for( int i = 1; i <= n; ++i ){
		for( int j = 1; j <= n; ++j ){
			if( in[i][j] == 0 ){
				pair p = { i, j };
				q.push(p);
			}
		}
	}
	while( !q.empty() ){
		f();
	}
	printf("%d\n",result+1);
	return 0;
}
