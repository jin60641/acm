#include<stdio.h>

int main(){
	long long int K, N, arr[10001],left,right,mid;
	long long int max = 0;
	long long int result = 0;
	scanf("%lld %lld",&K,&N);
	for( long long int i = 1; i <= K; ++i ){
		scanf("%lld",&arr[i]);
		if( arr[i] > max ){
			max = arr[i];
		}
	}
	left = 1;
	right = max;
	long long int flag = 0;
	while( left <= right ){
		mid = (left+right)/2;
		if( mid-left == 0 ){
			flag = 1;
			mid = left+1;
		}
		long long int tot = 0;
		for( long long int i = 1; i <= K; ++i ){
			tot += arr[i]/mid;
		}

		if( result >= 1 ){
			if( tot >= N ){
				result = mid;
				left = mid;
			} else {
				if( flag ){
					result = left;
					break;
				}
				right = mid;
			}
		} else if( tot >= N ){
			result = mid;
			left = mid;
		} else if( tot < N ){
			right = mid;
		}
	}
	printf("%lld\n",result);
	return 0;
}
