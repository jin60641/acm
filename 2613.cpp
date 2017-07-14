#include<stdio.h>
#include<queue>
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
	std::queue<int> result;
	while( left <= right ){
		std::queue<int> q;
		int tmp = -1;
		int mid = (left+right)/2;
		int cnt = 0;
		for( int i = 0; i < N; ++i ){
			int sum_tmp = tmp>=0?sum[tmp]:0;
			int s = sum[i] - sum_tmp;
			if( s > mid ){
				s = a[i];
				int new_tmp = i-1;
				q.push( new_tmp-tmp );
				tmp = new_tmp;
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
			if( mid < min ){
				min = mid;
				while( result.size() > 0 ){
					result.pop();
				}
				while( q.size() > 0 ){
					result.push(q.front());
					q.pop();
				}
				result.push((N-1)-tmp);
			}
			right = mid - 1;
		} else if( cnt > M ){
			left = mid + 1;
		}
	}
	printf("%d\n",min);
	while( result.size() > 0 ){
		printf("%d ",result.front());
		result.pop();
	}
}
