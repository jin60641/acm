#include<stdio.h>
#include<algorithm>
using namespace std;

int cnt = 0;
int N;


int move( int n ){
	if( n == 0 ){
		return 0;
	}
	++cnt;
	
	for( int i = n-1; i >= 1; --i ){
		move(i);
	}
	return 0;
}


int main(){
	scanf("%d",&N);
	for( int i = 1; i <= N; ++ i ){
		move(i);
	}
	printf("%d",cnt);

	return 0;
}

