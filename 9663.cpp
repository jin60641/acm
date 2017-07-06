#include<stdio.h>

const int MAX_N = 15;

int check[MAX_N][MAX_N];
int main(){
	int result = 0;
	int cnt = 0;
	int N;
	int flag = 0;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			if( check[i][j] == 0 ){
				++cnt;
				for( int k = 0; k < N; ++k ){
					check[i][k] = 1;
				}
				for( int k = 0; k < N; ++k ){
					check[k][j] = 1;
				}
				int x,y;
				x = i;
				y = j;
				while( x < N && y < N ){
					check[x++][y++] = 1;
				}
				x = i;
				y = j;
				while( x < N && y >= 0 ){
					check[x++][y--] = 1;
				}
				x = i;
				y = j;
				while( x >= 0 && y >= 0 ){
					check[x--][y--] = 1;
				}
				x = i;
				y = j;
				while( x >= 0 && y < N ){
					check[x--][y++] = 1;
				}
				check[i][j] = 9;
				if( cnt == N ){
					flag = 1;
				}
			}
			if( flag == 1 ){
				break;
			}
		}
		if( flag == 1 ){
			break;
		}
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			printf("%d ",check[i][j]);
		}
		printf("\n");
	}
	return 0;
}
