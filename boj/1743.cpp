#include<stdio.h>

int N,M,K;
int check[102][102];

int arr[102][102];
int dfs(int y,int x){
	if( arr[y][x] == 0 ){
		check[y][x] = 1;
	}
	if( check[y][x] == 1 ){
		return 0;
	}
	check[y][x] = 1;
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int ret = 1;
	for( int i = 0; i < 4; ++i ){
		ret += dfs(y+dy[i],x+dx[i]);
	}
	return ret;
}
int max( int a, int b ){
	return a>b?a:b;
}

int main(){
	scanf("%d %d %d",&N,&M,&K);
	for( int i = 0; i < K; ++i ){
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b] = 1;
	}
	int result = 0;
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= M; ++j ){
			if( check[i][j] == 0 && arr[i][j] == 1 ){
				result = max( result, dfs(i,j) );
			}
		}
	}
	printf("%d",result);
}
