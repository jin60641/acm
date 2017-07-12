#include<stdio.h>
int a[600][600];
int Y,X,H;

int f(int y,int x){
	if( y == Y && x == X ){
		++H;
		return 0;
	}
	if( y < Y && ( a[y+1][x] < a[y][x] ) ){
		f(y+1,x);
	}
	if( y > 1 && ( a[y-1][x] < a[y][x] ) ){
		f(y-1,x);
	}
	if( x < X && ( a[y][x+1] < a[y][x] ) ){
		f(y,x+1);
	}
	if( x > 1 && ( a[y][x-1] < a[y][x] ) ){
		f(y,x-1);
	}
	return 0;
}


int main(){
	scanf("%d %d",&Y,&X);
	for( int i = 1; i <= Y; ++i ){
		for( int j = 1; j <= X; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	f(1,1);
	printf("%d\n",H);
	return 0;
}
