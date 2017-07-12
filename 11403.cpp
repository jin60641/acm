#include<stdio.h>

const int MAX = 100;
int a[MAX][MAX];

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	int flag = 1;
	while( flag == 1 ){
		flag = 0;
		for( int i = 0; i < N; ++i ){
			for( int j = 0; j < N; ++j ){
				if( a[i][j] == 1 ){
					for( int k = N-1; k >= 0; --k ){
						if( a[j][k] == 1 && a[i][k] == 0 ){
							flag = 1;
							a[i][k] = 1;
						}
					}
				}
			}
		}
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
