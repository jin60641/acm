#include<stdio.h>

const int MAX = 100;
int a[MAX][MAX];

int main(){
	int N,M;
	scanf("%d",&N);
	scanf("%d",&M);
	while(M--){
		int A,B;
		scanf("%d %d",&A,&B);
		a[A-1][B-1] = 1;
		a[B-1][A-1] = 2;
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
							a[k][i] = 2;
						}
					}
				}
			}
		}
	}
	for( int i = 0; i < N; ++i ){
		int cnt = -1;
		for( int j = 0; j < N; ++j ){
			if( a[i][j] == 0 ){
				++cnt;
			}
		}
		printf("%d\n",cnt);
	}
}
