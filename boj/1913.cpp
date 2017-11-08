#include<stdio.h>

int a[999][999];

int main(){
	int N;
	int X;
	scanf("%d",&N);
	scanf("%d",&X);
	int num = 1;
	int x = N/2;
	int y = N/2;
	int flag = 0;
	int flagX[4] = {0,1,0,-1};
	int flagY[4] = {-1,0,1,0};
	int cnt = 0;
	int max = 1;
	while(num<=N*N){
		a[y][x] = num++;
		++cnt;
		x += flagX[flag];
		y += flagY[flag];
		if( max == cnt ){
			flag = ++flag%4;
			if( flag%2 == 0 ){
				++max;
			}
			cnt = 0;
		}
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			if( a[i][j] == X ){
				x = j;
				y = i;
			}
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("%d %d\n",y+1,x+1);
	
	return 0;
}
