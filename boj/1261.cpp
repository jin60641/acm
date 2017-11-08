#include<stdio.h>
#include<queue>
#include<vector>
struct pos {
	int y, x;
};
const int INF = 100000;
int N, M, arr[102][102], dist[102][102];
struct cmp {
	bool operator()( pos a, pos b ){
		return dist[a.y][a.x] > dist[b.y][b.x];
	}
};
std::priority_queue<pos,std::vector<pos>,cmp> q;
void f(){
	pos now = q.top();
	q.pop();
	pos d[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	for( int i = 0; i < 4; ++i ){
		pos dn = { now.y + d[i].y, now.x + d[i].x };
		if( dist[dn.y][dn.x] != -1 && dist[now.y][now.x] + arr[dn.y][dn.x] < dist[dn.y][dn.x] ){
			dist[dn.y][dn.x] = dist[now.y][now.x] + arr[dn.y][dn.x];
			q.push(dn);
		}
	}
}
int main(){
	scanf("%d %d",&M,&N);
	for( int i = 0; i <= N+1; ++i ){
		for( int j = 0; j <= M+1; ++j ){
			dist[i][j] = -1;
		}
	}
	for( int i = 1; i <= N; ++i ){
		char s[110];
		scanf("%s",&s[1]);
		for( int j = 1; j <= M; ++j ){
			arr[i][j] = s[j]-'0';
			dist[i][j] = INF;
		}
	}
	dist[1][1] = 0;
	pos start = { 1, 1 };
	q.push(start);
	while( q.size() > 0 ){
		f();
	}
	printf("%d\n",dist[N][M]);
	return 0;
}
