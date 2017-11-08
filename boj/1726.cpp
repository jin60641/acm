#include<stdio.h>
#include<queue>

const int EAST = 1;
const int WEST = 2;
const int SOUTH = 3;
const int NORTH = 4;

int a[101][101],X,Y,check[101][101][5];

struct pos {
	int x;
	int y;
	int way;
	int cnt;
};

std::queue<pos> q;

pos start,end;

int turn(int from, int to){
	if( from == to ){
		return 0;
	} else if( from == EAST ){
		if( to == WEST ){
			return 2;
		} else {
			return 1;
		}
	} else if( from == WEST ){
		if( to == EAST ){
			return 2;
		} else {
			return 1;
		}
	} else if( from == SOUTH ){
		if( to == NORTH ){
			return 2;
		} else {
			return 1;
		}
	} else if( from == NORTH ){
		if( to == SOUTH ){
			return 2;
		} else {
			return 1;
		}
	}
}

int bfs(){
	pos now = q.front();
	int y = now.y;
	int x = now.x;
	int way = now.way;
	int cnt = now.cnt;

	int flag[5] = {0,0,0,0,0};
	for( int to = EAST; to <= NORTH; ++to ){
		if( check[y][x][to] == 0 || check[y][x][to] > cnt + turn(way,to) ){
			flag[to] = 1;
			check[y][x][to] = cnt + turn(way,to);
		}
	}
	if( end.y == y && end.x == x ){
		q.pop();
		return 0;
	}
	if( flag[EAST] == 1 ){
		for( int i = x+1; i <= X && i <= x+3; ++i ){
			if( a[y][i] == 1 ){
				break;
			}
			pos tmp = { i, y, EAST, check[y][x][EAST]+1 };
			q.push(tmp);
		}
	}
	if( flag[WEST] == 1 ){
		for( int i = x-1; i >= 1 && i >= x-3; --i ){
			if( a[y][i] == 1 ){
				break;
			}
			pos tmp = { i, y, WEST, check[y][x][WEST]+1 };
			q.push(tmp);
		}
	}
	if( flag[SOUTH] == 1 ){		
		for( int i = y+1; i <= Y && i <= y+3; ++i ){
			if( a[i][x] == 1 ){
				break;
			}
			pos tmp = { x, i, SOUTH, check[y][x][SOUTH]+1 };
			q.push(tmp);
		}
	}
	if( flag[NORTH] == 1 ){
		for( int i = y-1; i >= 1 && i >= y-3; --i ){
			if( a[i][x] == 1 ){
				break;
			}
			pos tmp = { x, i, NORTH, check[y][x][NORTH]+1 };
			q.push(tmp);
		}
	}
	q.pop();
	return 0;
}

int main(){
	scanf("%d %d",&Y,&X);
	for( int i = 1; i <= Y; ++i ){
		for( int j = 1; j <= X; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d %d",&start.y,&start.x,&start.way);
	scanf("%d %d %d",&end.y,&end.x,&end.way);
	start.cnt = 0;
	q.push(start);
	while( q.size() > 0 ){
		bfs();
	}
	printf("%d",check[end.y][end.x][end.way]);
	return 0;
}
