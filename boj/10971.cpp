#include<stdio.h>
int N, start, a[10][10], b[10][10];
int min( int a, int b ){
	return a<b?a:b;
}
void clear(){
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < N; ++j )
			b[i][j] = a[i][j];
}
int dfs( int now, int cnt ){
	if( cnt == N ){
		return b[now][start]==0?30000000:b[now][start];
	}
	int ret = 30000000;
	int tmp[10][10];
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < N; ++j )
			tmp[i][j] = b[i][j];
	for( int i = 0; i < N; ++i ){
		if( i != start && i != now && b[now][i] != 0 ){
			for( int j = 0; j < N; ++j ){
				b[now][j] = 0;
				b[j][i] = 0;
			}
			ret = min( ret, tmp[now][i] + dfs( i ,cnt+1 ) );
			for( int j = 0; j < N; ++j ){
				b[now][j] = tmp[now][j];
				b[j][i] = tmp[j][i];
			}
		}
	}
	return ret;
}
int main(){
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	int result = 30000000;
	for( int i = 0; i < N; ++i ){
		clear();
		start = i;
		result = min( result, dfs(i,1) );
	}
	printf("%d\n",result);
}
