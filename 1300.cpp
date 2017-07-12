#include<stdio.h>

int main(){
	long long int N;
	scanf("%d",&N);
	int k;
	scanf("%d",&k);

	long long int left = 1;
	long long int right = N*N;
	while( left <= right ){
		long long int mid = (left+right)/2;
		long long int tot = 0;
		for( long long int i = 1; i <= N; ++i ){
			if( mid > i*N ){
				tot += N;
			} else {
				tot += mid/i;
			}
		}
		if( tot < k ){
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	printf("%lld\n",left);
	
	return 0;
}
