#include<stdio.h>

int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	int sum[100000];
	int a[100000];
	int left = 0;
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
		left = a[i]>left?a[i]:left;
	}
	sum[0] = a[0];
	for( int i = 1; i < N; ++i ){
		sum[i] = sum[i-1]+a[i];
	}
	int right = sum[N-1];
	int min = right;
	while( left <= right ){
		int tmp = -1;
		int mid = (left+right)/2;
		int cnt = 0;
		for( int i = 0; i < N; ++i ){
			int sum_tmp = tmp>=0?sum[tmp]:0;
			int s = sum[i] - sum_tmp;
			if( s > mid ){
				s = a[i];
				tmp = i-1;
				++cnt;
			}
			if( s > 0 && i+1 == N ){
				++cnt;
			}
			if( cnt > M ){
				break;
			}
		}
		if( cnt <= M ){
			min = mid<min?mid:min;
			right = mid - 1;
		} else if( cnt > M ){
			left = mid + 1;
		}
	}
	printf("%d\n",min);
}
