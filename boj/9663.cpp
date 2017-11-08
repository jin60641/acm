#include<stdio.h>
struct pos {
	int x,y;
};
int result = 0;
int N;
int check[15][15][15];
int put( int cnt, pos p ){
	if( cnt == N ){
		return ++result;
	}
	for( int y = p.y; y < N; ++y ){
		for( int x = 0; x < N; ++x ){
			check[cnt][x][y] = check[cnt-1][x][y];
		}
	}
	int x = p.x;
	int y = p.y;
	for( int i = y; i < N; ++i ){
		check[cnt][x][i] = 1;
	}
	while( x < N && y < N ){
		check[cnt][x++][y++] = 1;
	}
	x = p.x;
	y = p.y;
	while( x >= 0 && y < N ){
		check[cnt][x--][y++] = 1;
	}
	for( int j = 0; j < N; ++j ){
		if( check[cnt][j][p.y+1] == 0 ){
			pos a = { j, p.y+1 };
			put( cnt+1, a );
		}
	}
	return 0;
}
int main(){
	scanf("%d",&N);
	for( int x = 0; x < N; ++x ){
		pos p = { x, 0 };
		put( 1, p );
	}
	printf("%d\n",result);
	return 0;
}

