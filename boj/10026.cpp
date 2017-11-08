#include<stdio.h>
#include<queue>
int check[101][101];
char a[102][102];
struct pos {
	int y,x;
};
std::queue<pos> q;
int bfs(){
	int y = q.front().y;
	int x = q.front().x;
	q.pop();
	int dy[4] = { 0, 0, -1, 1 };
	int dx[4] = { -1, 1, 0, 0 };
	for( int i = 0; i < 4; ++i ){
		if( check[y+dy[i]][x+dx[i]] == 0 && a[y+dy[i]][x+dx[i]] == a[y][x] ){
			pos p = { y+dy[i], x+dx[i] };
			check[y+dy[i]][x+dx[i]] = 1;
			q.push(p);
		}
	}
	return 0;
}
int init( int N ){
	int ret = 0;
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			if( check[i][j] == 0 ){
				++ret;
				pos p = { i, j };
				q.push(p);
				check[i][j] = 1;
				while( q.size() > 0 ){
					bfs();
				}
			}
		}
	}
	return ret;
}
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i <= N; ++i ){
		a[0][i] = 0;
		a[i][0] = 0;
		a[0][N+1] = 0;
		a[N+1][0] = 0;
	}
	for( int i = 1; i <= N; ++i ){
		scanf("%s",a[i]+1);
	}
	printf("%d ",init(N));
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			check[i][j] = 0;
			a[i][j] = a[i][j]=='R'?'G':a[i][j];
		}
	}
	printf("%d\n",init(N));
	return 0;
}
