#include<stdio.h>
#include<vector>
#include<queue>
int Y,X,H;
struct pos {
	int y,x;
};
std::vector<pos> v[501][501];
std::queue<pos> q;
int a[501][501];
int in[501][501];
int cnt[501][501];
int check[501][501];

void swap( int &a, int &b ){
	int tmp = a;
	a = b;
	b = tmp;
}

void bfs(){
	pos now = q.front();
	pos d[4] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
	for( int i = 0; i < 4; ++i ){
		int dy = now.y + d[i].y;
		int dx = now.x + d[i].x;
		if( ( dy != 1 || dx != 1 ) && a[dy][dx] < a[now.y][now.x] && check[dy][dx] == 0 && ( in[dy][dx] >= 1 && --in[dy][dx] == 0 ) ){
			pos next = { dy, dx };
			check[dy][dx] = 1;
			q.push(next);
		}
	}
}

void f(){
	pos now = q.front();
	for( int i = v[now.y][now.x].size() - 1; i >= 0; --i ){
		pos next = v[now.y][now.x][i];
		int ny = next.y, nx = next.x;
		cnt[ny][nx] += cnt[now.y][now.x];
		if( in[ny][nx] >= 1 && --in[ny][nx] == 0 ){
			q.push(next);
		}
	}
}

int main(){
	scanf("%d %d",&Y,&X);
	for( int i = 1; i <= Y; ++i ){
		for( int j = 1; j <= X; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	pos d[2] = { { 0, 1 }, { 1, 0 } };
	for( int i = 1; i <= Y; ++i ){
		for( int j = 1; j <= X; ++j ){
			for( int k = 0; k < 2; ++k ){
				int ti = i, tj = j;
				int di = i+d[k].y, dj = j+d[k].x;
				if( a[di][dj] != 0 && a[i][j] != a[di][dj] ){
					if( a[i][j] < a[di][dj] ){
						swap(ti,di);
						swap(tj,dj);
					}
					pos p = { di, dj };
					v[ti][tj].push_back(p);
					in[di][dj] += 1;
				}
			}
		}
	}
	check[1][1] = 1;
    for( int i = 1; i <= Y; ++i ){
        for( int j = 1; j <= X; ++j ){
			if( ( i != 1 || j != 1 ) && check[i][j] == 0 && in[i][j] == 0 ){
				pos p = { i, j };
				q.push(p);
				while(q.size()>0){
					bfs();
					q.pop();
				}
			}
        }
    }
	cnt[1][1] = 1;
	pos start = { 1, 1 };
	q.push(start);
	while(q.size()>0){
		f();
		q.pop();
	}
	printf("%d\n",cnt[Y][X]);
	return 0;
}
