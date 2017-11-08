#include<stdio.h>

int min[5001];
int N;

int f(int s, int cnt){
	if( s > N ){
	} else if( min[s] <= cnt ){
	} else if( s == N ){
		min[s] = cnt;
	} else {
		min[s] = cnt;
		f(s+3,cnt+1);
		f(s+5,cnt+1);
	}
	return 0;
}

int main(){
	scanf("%d",&N);
	for( int i = 0; i <= N; ++i ){
		min[i] = 10000000;
	}
	f(0,0);
	if( min[N] == 10000000 ){
		printf("-1\n");
	} else {
		printf("%d",min[N]);
	}
}
