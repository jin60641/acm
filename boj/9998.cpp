#include<stdio.h>
long long int max( long long int a, long long int b ){
	return a>b?a:b;
}
long long int min( long long int a, long long int b ){
	if( a == -1LL ){
		return b;
	}
	return a<b?a:b;
}
long long int abs( long long int a ){
	return a<0LL?-a:a;
}
int main(){
	int N;
	long long int a[300001];
	long long int b[300001];
	long long int left = 0;
	long long int right = 0;
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		scanf("%lld",&a[i]);
	}
	for( int i = 1; i <= N; ++i ){
		scanf("%lld",&b[i]);
		right = max( a[i], max( right, b[i] ) );
	}
	int center = N/2+1;
	long long int result = -1LL;
	while( left <= right ){
		long long int mid = (left+right)/2LL;
		long long int sum[3] = { 0, 0, 0 };
		for( int i = 1; i <= N; ++i ){
			sum[0] += abs( (mid-1+abs(i-center))-a[i] ) + abs( (mid-1+abs(i-center))-b[i] );
			sum[1] += abs( (mid+abs(i-center))-a[i] ) + abs( (mid+abs(i-center))-b[i] );
			sum[2] += abs( (mid+1+abs(i-center))-a[i] ) + abs( (mid+1+abs(i-center))-b[i] );
		}
		if( sum[0] > sum[1] && sum[1] < sum[2] ){
			result = sum[1];
			break;
		} else if( sum[0] > sum[1] && sum[1] >= sum[2] ){
			result = min( result, sum[1] );
			left = mid + 1LL;
		} else if( sum[0] <= sum[1] && sum[1] < sum[2] ){
			result = min( result, sum[1] );
			right = mid - 1LL;
		} else if( sum[0] == sum[1] && sum[1] == sum[2] ){
			result = min( result, sum[1] );
			break;
		}
	}
	printf("%lld\n",result);
	return 0;
}
