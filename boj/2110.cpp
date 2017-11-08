#include<stdio.h>
#include<algorithm>

int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	int x[200000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&x[i]);
	}
	std::sort(x,x+N);
	int left = x[0];
	int right = x[N-1];
	int max = 0;
	while( left <= right ){
		int tmp = 0;
		int mid = (left+right)/2;
		int cnt = 1;
		for( int i = 1; i < N; ++i ){
			int s = x[i] - x[tmp];
			if( s >= mid ){
				tmp = i;
				++cnt;
			}
			if( cnt > M ){
				break;
			}
		}
		if( cnt < M ){
			right = mid - 1;
		} else if( cnt >= M ){
			max = mid>max?mid:max;
			left = mid + 1;
		}
	}
	printf("%d\n",max);
}
