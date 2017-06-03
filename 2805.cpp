#include<stdio.h>

int arr[1000001];
int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	int max = -1;
	for( int i = 0; i < N; ++i ){
		scanf("%d",&arr[i]);
		if( arr[i] > max ){
			max = arr[i];
		}
	}
	int left = 1;
	int right = max;
	int mid;
	while( left <= right ){
		long long int tot = 0;
		mid = (left+right)/2;
		for( int i = 0; i < N; ++i ){
			if( arr[i]-mid >= 0 )
				tot += arr[i]-mid;
		}
		if( tot >= M ){
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	printf("%d\n",left-1);
	return 0;
}
