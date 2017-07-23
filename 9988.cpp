#include<stdio.h>

long long int max( long long int a, long long int b ){
	return a>b?a:b;
}

long long int min( long long int a, long long int b ){
	if( a == -1 ){
		return b;
	}
	return a<b?a:b;
}

long long int abs( long long int a ){
	return a<0?-a:a;
}

int main(){
	long long int N;
	scanf("%d",&N);
	long long int a[300000];
	long long int b[300000];
	long long int left = 0;
	long long int right = 0;
	for( long long int i = 0; i < N; ++i ){
		scanf("%lld",&a[i]);
		right = max( right, a[i] );
	}
	for( long long int i = 0; i < N; ++i ){
		scanf("%lld",&b[i]);
		right = max( right, b[i] );
	}
	long long int result = -1;
	while( left <= right ){
		long long int mid = (left+right)/2;
		long long int tmp = 0;
		for( long long int i = 0; i < N; ++i ){
			tmp += abs(a[i] - mid) + abs(b[i] - mid);
		}
		result = min( result, tmp );

		if(  ){
		} else {
		}
	}
	printf("%lld",result);
	return 0;
}
