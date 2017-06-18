#include<stdio.h>

int top[500001];
int bottom[500001];
int min = 1000000;
int min_cnt=0;

int main(){
	int N,H;
	scanf("%d %d",&N,&H);
	int flag = 1;
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		if( flag == 1 ){
			bottom[a]++;
			flag = 0;
		} else {
			top[a]++;
			flag = 1;
		}
	}
	for( int i = H-1; i >= 1; --i ){
		top[i] += top[i+1];
		bottom[i] += bottom[i+1];
	}
	for( int i = 1; i <= H; ++i ){
		int sum = top[H-i+1] + bottom[i];
		if( sum < min ){
			min = sum;
			min_cnt = 1;
		} else if( sum == min ){
			++min_cnt;
		}
	}
	printf("%d %d\n",min,min_cnt);
}
