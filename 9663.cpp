#include<stdio.h>

int N;
const int MAX_N = 15;
int check[MAX_N][MAX_N];

int clear(){
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			check[i][j] = 0;
		}
	}
	return 0;
}

int main(){
	int result = 0;
	scanf("%d",&N);
	int startI = 0;
	int startJ = 0;
	while( startI < N ){
		int flag = 0;
		int cnt = 0;
		for( int i = startI; i < N; ++i ){
			int tmpJ;
			if( i == startI ){
				tmpJ = startJ;
			} else {
				tmpJ = 0;
			}
			for( int j = tmpJ; j < N; ++j ){
				if( check[i][j] == 0 ){
					++cnt;
					for( int k = 0; k < N; ++k ){
						if( check[i][k] != 9 ){
							check[i][k] = 1;
						}
					}
					for( int k = 0; k < N; ++k ){
						if( check[i][k] != 9 ){
							check[k][j] = 1;
						}
					}
					int x,y;
					y = i;
					x = j;
					while( x < N && y < N ){
						if( check[y][x] != 9 ){
							check[y][x] = 1;
						}
						++x;
						++y;
					}
					y = i;
					x = j;
					while( x < N && y >= 0 ){
						if( check[y][x] != 9 ){
							check[y][x] = 1;
						}
						++x;
						--y;
					}
					y = i;
					x = j;
					while( x >= 0 && y >= 0 ){
						if( check[y][x] != 9 ){
							check[y][x] = 1;
						}
						--x;
						--y;
					}
					y = i;
					x = j;
					while( x >= 0 && y < N ){
						if( check[y][x] != 9 ){
							check[y][x] = 1;
						}
						--x;
						++y;
					}
					check[i][j] = 9;
					if( cnt == N ){
						flag = 1;
					}
					/*
					for( int i = 0; i < N ; ++i ){
						for( int j = 0; j < N; ++j ){
							printf("%d ",check[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					*/
				}
				if( flag == 1 ){
					break;
				}
			}
			if( flag == 1 ){
				break;
			}
		}
		printf("%d/%d : %d\n",startI,startJ,cnt);
		for( int i = 0; i < N ; ++i ){
			for( int j = 0; j < N; ++j ){
				printf("%d ",check[i][j]);
			}
			printf("\n");
		}
		//break;
		++startJ;
		if( startJ == N ){
			startI = 10;
			startJ = 0;
			++startI;
		}
		if( flag == 1 ){
			++result;
		}
		clear();
	}
	printf("%d\n",result);
	return 0;
}
