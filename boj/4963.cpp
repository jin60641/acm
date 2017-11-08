#include<stdio.h>
#include<queue>
struct pos {
	int y,x;
};
std::queue<pos> q;
int a[51][51];
int check[51][51];
int w,h,cnt;

pos d[8] = { 
	{ -1, -1 },	{ -1, 0 },	{ -1, 1 },
	{ 0, -1 },			 	{ 0, 1 },
	{ 1, -1 },	{ 1, 0 },	{ 1, 1 },
};

int bfs(){
	int y = q.front().y;
	int x = q.front().x;
	if( y == 0 || x == 0 || y == h+1 || x == w+1 || a[y][x] == 0 ){
		q.pop();
		return 0;
	}
	if( check[y][x] == 1 ){
		q.pop();
		return 0;
	}
	check[y][x] = 1;
	for( int i = 0; i < 8; ++i ){
		pos p;
		p.y = y + d[i].y;
		p.x = x + d[i].x;
		q.push(p);
	}
	return 0;
}


int main(){
	while(true){
		cnt = 0;
		scanf("%d %d",&w,&h);
		if( w == 0 && h == 0 ){
			return 0;
		}
		for( int i = 1; i <= h; ++i ){
			for( int j = 1; j <= w; ++j ){
				check[i][j] = 0;
				scanf("%d",&a[i][j]);
			}
		}
		for( int i = 1; i <= h; ++i ){
			for( int j = 1; j <= w; ++j ){
				if( a[i][j] == 1 && check[i][j] == 0 ){
					++cnt;
					pos p;
					p.y = i;
					p.x = j;
					q.push(p);
					while( q.size() > 0 ){
						bfs();
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
