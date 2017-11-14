#include<stdio.h>
int main(){
	int N,a[1000],dp[1000];
	int path[1000], results[1000];
	scanf("%d", &N);
	for( int i = 0; i < N; ++i ){
		dp[i] = 1;
		scanf("%d",&a[i]);
		path[i] = -1;
	}
	for( int i = 1; i < N; ++i ){
		for( int j = 0; j < i; ++j ){
			if( a[j] < a[i] ){
				if( dp[i] < dp[j]+1 ){
					path[i] = j;
					dp[i] = dp[j]+1;
				}
			}
		}
	}
	int result = -1;
	int index;
	for( int i = 0; i < N; ++i ){
		if( result < dp[i] ){
			result = dp[i];
			index = i;
		}
	}
	printf("%d\n",result);
	for( int i = 0; i < result; ++i ){
		results[i] = a[index];
		index = path[index];
	}
	for( int i = result-1; i >= 0; --i ){
		printf("%d ",results[i]);
	}
	printf("\n");
	return 0;
}
