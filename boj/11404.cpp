#include<stdio.h>

const int INF = 10000001;
int a[101][101];
int min( int a, int b ){
	return a<b?a:b;
}
int main(){
	int N,M;
	scanf("%d",&N);
	scanf("%d",&M);
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
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			if( i == j || a[i][j] == INF ){
				printf("0 ");
			} else {
				printf("%d ",a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
