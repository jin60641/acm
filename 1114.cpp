#include<stdio.h>
#include<algorithm>

int L, K, C, k[10010], left = 1, right;
int main(){
	scanf("%d %d %d",&L,&K,&C);
	right = L;
	for( int i = 1; i <= K; ++i ) scanf("%d",&k[i]);
	std::sort(k + 1, k + K + 1);
	int min = L+1;
	int first;
	while( left <= right ){
		int mid = (left+right)/2;
		int c = 0;
		int last = 0;
		int tmp = -1;
		for( int i = 1; i <= K; ++i ){
			int length = k[i] - k[last];
			if( length > mid ){
				if( i - last == 1 ){
					c = C+1000;
					break;
				} else {
					if( tmp == - 1 ){
						tmp = i-1;
					}
					++c;
					last = i-1;
					--i;
					continue;
				}
			} else if( length == mid ){
				++c;
				if( tmp == - 1 ){
					tmp = i;
				}
				last = i;
			}
		}
		if( L - k[last] > mid ){
			++c;
		}
		if( c <= C ){
			if( mid < min ){
				min = mid;
				first = tmp;
			}
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	left = 1;
	right = first;
	printf("%d ",min);
	int min2 = first;
	while( left <= right ){
		int mid = (left+right)/2;
		int c = 1;
		int last = mid;
		for( int i = mid+1; i <= K; ++i ){
			int length = k[i] - k[last];
			if( length > min ){
				if( i - last == 1 ){
					c = C+1000;
					break;
				} else {
					++c;
					last = i-1;
					--i;
					continue;
				}
			} else if( length == min ){
				++c;
				last = i;
			}
		}
		if( L - k[last] > min ){
			++c;
		}
		if( c <= C ){
			right = mid-1;
			min2 = min2>mid?mid:min2;
		} else {
			left = mid+1;
		}
	}
	printf("%d\n",k[min2]);
	return 0;
}
