#include<stdio.h>
#include<queue>

struct pos {
	int x,y;
};

struct pair {
	int weight;
	pos p;
};

std::queue<pair> q;

pos end;

int check[300][300];
int l;
int clear(){
	for( int i = 0; i < l; ++i ){
		for( int j = 0; j < l; ++j ){
			check[i][j] = 0;
		}
	}
}

int bfs(){
	pair now = q.front();
	if( now.p.x == end.x && now.p.y == end.y ){
		printf("%d\n",now.weight);
		while( q.size() > 0 ){
			q.pop();
		}
		return 0;
	}
	if( now.p.x >= 1 && now.p.y >= 2 && check[now.p.x-1][now.p.y-2] == 0 ){
		check[now.p.x-1][now.p.y-2] = 1;
		pos next = { now.p.x-1, now.p.y-2 };
		pair p = { now.weight+1,next };
		q.push(p);
	}
	if( now.p.x >= 2 && now.p.y >= 1 && check[now.p.x-2][now.p.y-1] == 0 ){
		check[now.p.x-2][now.p.y-1] = 1;
		pos next = { now.p.x-2, now.p.y-1 };
		pair p = { now.weight+1,next };
		q.push(p);
	}
	if( now.p.x < l-1 && now.p.y >= 2 && check[now.p.x+1][now.p.y-2] == 0 ){
		check[now.p.x+1][now.p.y-2] = 1;
		pos next = { now.p.x+1, now.p.y-2 };
		pair p = { now.weight+1,next };
		q.push(p);
	}
	if( now.p.x < l-2 && now.p.y >= 1 && check[now.p.x+2][now.p.y-1] == 0 ){
		check[now.p.x+2][now.p.y-1] = 1;
		pos next = { now.p.x+2, now.p.y-1 };
		pair p = { now.weight+1,next };
		q.push(p);
	}
	if( now.p.x >= 1 && now.p.y < l-2 && check[now.p.x-1][now.p.y+2] == 0 ){
		check[now.p.x-1][now.p.y+2] = 1;
		pos next = { now.p.x-1, now.p.y+2 };
		pair p = { now.weight+1,next };
		q.push(p);
	}
	if( now.p.x >= 2 && now.p.y < l-1 && check[now.p.x-2][now.p.y+1] == 0 ){
		check[now.p.x-2][now.p.y+1] = 1;
		pos next = { now.p.x-2, now.p.y+1 };
		pair p = { now.weight+1,next };
		q.push(p);
	}
	if( now.p.x < l-1 && now.p.y < l-2 && check[now.p.x+1][now.p.y+2] == 0 ){
		check[now.p.x+1][now.p.y+2] = 1;
		pos next = { now.p.x+1, now.p.y+2 };
		pair p = { now.weight+1,next };
		q.push(p);
	}
	if( now.p.x < l-2 && now.p.y < l-1 && check[now.p.x+2][now.p.y+1] == 0 ){
		check[now.p.x+2][now.p.y+1] = 1;
		pos next = { now.p.x+2, now.p.y+1 };
		pair p = { now.weight+1,next };
		q.push(p);
	}
	q.pop();
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&l);
		pos start;
		scanf("%d %d",&start.x,&start.y);
		scanf("%d %d",&end.x,&end.y);
		pair p = { 0, start };
		q.push(p);
		while( q.size() > 0){
			bfs();
		}
		clear();
	}
	return 0;
}
