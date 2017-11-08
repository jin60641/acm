#include<stdio.h>
const int INF = 200000001;
int a[404][404];
int min( int a, int b ){
	return a<b?a:b;
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			a[i][j] = INF;
		}
	}
	while(M--){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		a[A][B] = min(a[A][B],C);
	}
	int flag = 1;
	while( flag == 1 ){
		flag = 0;
		for( int i = 1; i <= N; ++i ){
			for( int j = 1; j <= N; ++j ){
				if( a[i][j] != INF ){
					for( int k = N; k >= 1; --k ){
						if( a[j][k] != INF && a[i][k] > a[i][j]+a[j][k] ){
							flag = 1;
							a[i][k] = a[i][j]+a[j][k];
						}
					}
				}
			}
		}
	}
	int result = INF;
	for( int i = 1; i <= N; ++i ){
		result = min( result, a[i][i] );
	}
	printf("%d\n",result==INF?-1:result);
	return 0;
}
