#include<stdio.h>

int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	char a[50][51];
	for( int i = 0; i < N; ++i ){
		scanf("%s",a[i]);
	}
	int x = 0;
	int y = 0;
	for( int i = 0; i < N; ++i ){
		int flag = 1;
		for( int j = 0; j < M; ++j ){
			if( a[i][j] == 'X' ){
				flag = 0;
			}
		}
		if( flag ){
			++x;
		}
	}
	for( int i = 0; i < M; ++i ){
		int flag = 1;
		for( int j = 0; j < N; ++j ){
			if( a[j][i] == 'X' ){
				flag = 0;
			}
		}
		if( flag ){
			++y;
		}
	}
	printf("%d\n",x>y?x:y);
	return 0;
}
