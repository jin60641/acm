#include<stdio.h>
int check[500000];
int main(){
	int N,P;
	scanf("%d %d",&N,&P);
	int cnt = 0;
	for( int i = 0; i < N; ++i ){
		int n,p;
		scanf("%d",&n,&p);
		if(	check[n] == 0 ){
			check[n] = p;
			++cnt;
		} else if( check[n] < p ){
			check[n] = p;
			++cnt;
		} else if( check[n] > p ){
			check[n] = 2;
			cnt+=2;
		}
	}
}
