#include<stdio.h>

long long int a[100][100];
long long int check[100][100];
long long int cnt = 0;
long long int N;
long long int f(long long int y, long long int x ){
	if( y >= N || x >= N ){
		return 0;
	}
	if( check[y][x] != 0 ){
		return check[y][x];
	}
	if( y == N-1 && x == N-1 ){
		return 1;
	} else if( a[i][j] == 0 ){
		return 0;
	}
	long long int ret = f(y+a[y][x],x) + f(y,x+a[y][x]);
	check[y][x] = ret;
	return ret;
}
int main(){
	scanf("%lld",&N);
	for( long long int i = 0; i < N; ++i ){
		for( long long int j = 0; j < N; ++j ){
			scanf("%lld",&a[i][j]);
		}
	}	
	printf("%lld\n",f(0,0));
	return 0;
}
