#include<stdio.h>

int max( int a, int b ){
	return a>b?a:b;
}

int min( int a, int b ){
	return a<b?a:b;
}

int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	int a[300000];
	int left = 1;
	int right = 0;
	int result = 200000000;
	for( int i = 0; i < M; ++i ){
		scanf("%d",&a[i]);
		right += a[i];
	}
	while( left <= right ){
		int mid = ( left + right ) / 2;
		int cnt = 0;
		int tmp = 0;
		for( int i = 0; i < M; ++i ){
			if( cnt + a[i]/mid ){
				
			}
			tmp = max( tmp, mid + a[i]%mid );
			cnt += a[i]/mid;
		}
		printf("mid : %d / cnt : %d / tmp : %d\n",mid,cnt,tmp);
		if( cnt >= N ){
			left = mid+1;
			result = min( result, tmp );
		} else {
			right = mid-1;
		}
	}
	printf("%d",result);
	return 0;
}
