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
	long long int left = 0;
	long long int right = 0;
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		scanf("%lld",&a[i]);
	}
	for( int i = 1; i <= N; ++i ){
		long long int tmp;
		scanf("%lld",&tmp);
		a[i] = (a[i] + tmp)/2LL;
		right = max( right, a[i] );
	}
	int center = N/2+1;
	long long int result = -1LL;
	while( left <= right ){
		long long int mid = (left+right)/2LL;
		long long int sum = 0;
		long long int plus = 0;
		long long int minus = 0;
		for( int i = 1; i <= N; ++i ){
			long long int tmp = (mid+abs(i-center))-a[i];
			if( tmp > 0 ){
				plus += tmp;
			} else { 
				minus += abs(tmp);
			}
			sum += abs(tmp);
		}
		result = min(result,sum);
		if( plus > minus ){
			right = mid - 1LL;
		} else if( plus < minus ){
			left = mid + 1LL;
		} else {
			break;
		}
	}
	printf("%lld\n",result*2);
	return 0;
}
