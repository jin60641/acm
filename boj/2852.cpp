#include<stdio.h>

int cnt[2880];
int main(){
	int N;
	scanf("%d",&N);
	while( N >= 1){
		int t,h,m;
		scanf("%d %d:%d",&t,&h,&m);
		if( t == 2 ){
			t = 1;
		} else {
			t = -1;
		}
		for( int i = h*60+m; i < 2880; ++i ){
			cnt[i] += t;
		}
		--N;
	}
	int a_win = 0;
	int b_win = 0;
	for( int i = 0; i < 2880; ++i ){
		if( cnt[i] <= -1 ){
			++a_win;
		} else if( cnt[i] >= 1 ){
			++b_win;
		}
	}

	printf("%02d:%02d\n",a_win/60,a_win%60);
	printf("%02d:%02d\n",b_win/60,b_win%60);
}
