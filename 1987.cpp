#include<stdio.h>

int check[30];
char arr[21][22];
int R,C;
int max( int a, int b ){
	return a>b?a:b;
}
int f(int y, int x, int cnt){
	if( y == -1 || y == R || x == -1 || x == C || check[ arr[y][x]-'A' ] == 1 ){
		return cnt-1;
	}
	check[ arr[y][x]-'A' ] = 1;
	int ret = 0;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	for( int i = 0; i < 4; ++i ){
		ret = max( ret, f(y+dy[i],x+dx[i],cnt+1) );
	}
	check[ arr[y][x]-'A' ] = 0;
	return ret;
}

int main(){
	scanf("%d %d",&R,&C);
	for( int i = 0; i < R; ++i ){
		scanf("%s",arr[i]);
	}
	printf("%d\n",f(0,0,1));
	return 0;
}
