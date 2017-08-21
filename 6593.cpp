#include<stdio.h>
#include<queue>
const int INF = 10000001;
struct pos {
	int z,y,x;
};
int L = 30,R = 30,C = 30;
pos S,E;

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

int arr[32][32][32];
int visit[32][32][32];
int result = INF;

int find(){
	pos now = pq.top().p;
	int weight = pq.top().w;
	pq.pop();
	if( now.z == E.z && now.y == E.y && now.x == E.x ){
		result = weight;
		return 0;
	}
	if( visit[now.z][now.y][now.x] == 0 ){
		visit[now.z][now.y][now.x] = 1;
		pos d[6] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };
		for( int i = 0; i < 6; ++i ){
			if( arr[now.z+d[i].z][now.y+d[i].y][now.x+d[i].x] == 1 && visit[now.z+d[i].z][now.y+d[i].y][now.x+d[i].x] == 0 ){
				pos p = { now.z+d[i].z, now.y+d[i].y, now.x+d[i].x };
				pair next = { p, weight + 1 };
				pq.push( next );
			}
		}
	}
	return 0;
}

void clear(){
	result = INF;
	for( int i = 0; i <= 31; ++i ){
		for( int j = 0; j <= 31; ++j ){
			for( int k = 0; k <= 31; ++k ){
				arr[i][j][k] = 0;
				visit[i][j][k] = 0;
			}
		}
	}
	while( pq.size() > 0 ){
		pq.pop();
	}
}


int main(){
	while( true ){
		clear();
		scanf("%d %d %d",&L,&R,&C);
		if( L == 0 && R == 0 && C == 0 ){
			break;
		}
		for( int i = 1; i <= L; ++i ){
			for( int j = 1; j <= R; ++j ){
				char s[31];
				scanf("%s",s);
				for( int k = 1; k <= C; ++k ){
					char c = s[k-1];
					arr[i][j][k] = (c == '#')?0:1;
					if( c == 'S' ){
						pos p = { i, j, k };
						S = p;
					} else if( c == 'E' ){
						pos p = { i, j, k };
						E = p;
					}
				}
			}
		}
		pair s = { S, 0 };
		pq.push(s);
		while( pq.size() > 0 && result == INF ){
			find();
		}
		if( result == INF ){
			printf("Trapped!\n");
		} else {
			printf("Escaped in %d minute(s).\n",result);
		}
	}
	return 0;
}
