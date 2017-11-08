#include<stdio.h>

int N,S;
int cnt = 0;
int a[21];

int find(int now, int sum){
	if( sum == S ){
		++cnt;
	}
	for( int i = now+1; i <= N; ++i ){
		find(i,sum+a[i]);
	}
	return 0;
}


int main(){
	scanf("%d %d",&N,&S);
	for( int i = 1; i <= N; ++i ){
		scanf("%d",&a[i]);
	}
	find(0,0);
	if( S == 0 ){
		--cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
