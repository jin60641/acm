#include<stdio.h>

int N, M,a[50][50], cnt = 0;
void flip(int y, int x){	
	++cnt;
	for( int i = y; i < y+3; ++i ){
		for( int j = x; j < x+3; ++j ){
			a[i][j] = !a[i][j];
		}
	}
}
int main(){
	scanf("%d %d",&N,&M);
	for( int i = 0; i < N; ++i ){
		char tmp[51];
		scanf("%s",tmp);
		for( int j = 0; j < M; ++j ){
			a[i][j] = tmp[j]-'0';
		}
	}
	for( int i = 0; i < N; ++i ){
		char tmp[51];
		scanf("%s",tmp);
		for( int j = 0; j < M; ++j ){
			a[i][j] = a[i][j]^(tmp[j]-'0');
		}
	}
	for( int i = 0; i < N-2; ++i ){
		for( int j = 0; j < M-2; ++j ){
			if( a[i][j] == 1 ){
				flip(i,j);
			}
		}
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < M; ++j ){
			if( a[i][j] == 1 ){
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
