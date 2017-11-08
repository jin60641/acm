#include<stdio.h>
#include<queue>
const int INF = 10000001;
struct pos {
	int y,x;
};
pos d[4] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

struct pair {
	pos p;
	int w;
};

struct cmp {
	bool operator()(pair a, pair b){
		return a.w > b.w;
	}
};
std::priority_queue<pair,std::vector<pair>,cmp> pq;

int N,arr[127][127],visit[127][127],result = INF;

int find(){
	pos now = pq.top().p;
	int y = now.y;
	int x = now.x;
	int weight = pq.top().w;
	pq.pop();
	if( x == N && y == N ){
		result = weight;
		return 0;
	}
	if( visit[y][x] == 0 ){
		visit[y][x] = 1;
		for( int i = 0; i < 4; ++i ){
			int dy = now.y + d[i].y;
			int dx = now.x + d[i].x;
			if( arr[dy][dx] >= 0 && visit[dy][dx] == 0 ){
				pos p = { dy, dx };
				pair next = { p, weight + arr[dy][dx] };
				pq.push( next );
			}
		}
	}
	return 0;
}

void clear(){
	result = INF;
	for( int i = 0; i < 127; ++i ){
		for( int j = 0; j < 127; ++j ){
			arr[i][j] = -1;
			visit[i][j] = 0;
		}
	}
	while( pq.size() > 0 ){
		pq.pop();
	}
}


int main(){
	int t = 1;
	while( true ){
		clear();
		scanf("%d",&N);
		if( N == 0 ){
			break;
		}
		for( int i = 1; i <= N; ++i ){
			for( int j = 1; j <= N; ++j ){
				scanf("%d", &arr[i][j] );
			}
		}
		pos S = { 1, 1 };
		pair s = { S, arr[1][1] };
		pq.push(s);
		while( pq.size() > 0 && result == INF ){
			find();
		}
		printf("Problem %d: %d\n",t++,result);
	}
	return 0;
}
