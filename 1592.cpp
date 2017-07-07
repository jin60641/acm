#include<stdio.h>

int cnt[1000];

int N,M,L;

int f(int c, int d){
	int num = c;
	if( num >= N ){
		num = num%N;
	} else if( num < 0 ){
		num += N;
	}
	++cnt[num];
	if( cnt[num] == M ){
		printf("%d\n",d);
	} else if( cnt[num]%2 == 1 ){
		f(num-L,d+1);
	} else {
		f(num+L,d+1);
	}
	return 0;
}

int main(){
	scanf("%d %d %d",&N,&M,&L);
	f(0,0);
}
