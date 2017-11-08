#include<stdio.h>
const int INF = 100000000;
int min( int a, int b ){
	return a<b?a:b;
}
int main(){
	int N, M, arr[101][101];
	scanf("%d %d", &N, &M );
	for( int i = 1; i <= N; ++i )
		for( int j = 1; j <= N; ++j )
			arr[i][j] = INF;
	for( int i = 0; i < M; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			for( int k = 1; k <= N; ++k ){
				if( arr[j][k] != INF ){
					arr[i][k] = min( arr[i][k], arr[i][j] + arr[j][k] );
				}
			}
		}
	}
	int result = INF;
	int result_index;
	for( int i = 1; i <= N; ++i ){
		int sum = 0;
		for( int j = 1; j <= N; ++j ){
			if( arr[i][j] != INF ){
				sum += arr[i][j];
			}
		}
		if( result > sum ){
			result = sum;
			result_index = i;
		}
	}
	printf("%d\n",result_index);
	return 0;
}
