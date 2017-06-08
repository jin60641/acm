#include<stdio.h>
#include<algorithm>

int top[100000];
int bottom[100000];
int cnt[500000];

int main(){
	int N,H;
	scanf("%d %d",&N,&H);
	int flag = 1;
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		if( flag == 1 ){
			bottom[i/2] = a;
			flag = 0;
		} else {
			top[i/2] = a;
			flag = 1;
		}
	}
	std::sort(bottom,bottom+N/2);
	std::sort(top,top+N/2);
	for( int i = 0; i < N/2; ++i ){
//		cnt[H-top[i]] += i;
		cnt[H-bottom[i]] += i;
	}
	std::sort(cnt,cnt+H);

	int left = 0;
	int right = H-1;
	int mid;
	//printf("%d ",cnt[0]);
	while( left <= right ){
		mid = (left+right)/2;
		if( cnt[mid] > cnt[0] ){
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	printf("\n%d\n",left);
	for( int i = 0; i < H; ++i ) {
		printf("%d ",cnt[i]);
	}
	printf("\n");
}
