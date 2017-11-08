#include<stdio.h>

int index = 0;
int arr[101][101][101];
int q[1001000];
int N,M,H;
int cnt = 0;

int push( int i, int j, int k){
	if( arr[i][j][k] == 0 ){
		arr[i][j][k] = 1;
		q[index] = i*M+j+k*(M*N);
		++index;
		return 0;
	}
}

int bfs(int start, int day ){
	int tmp = index;
	for( int i = start; i < tmp; ++i ){
		int k = q[i]/(M*N);
		int rest = q[i]%(M*N);
		int n = rest/M;
		int m = rest%M;
		if( n >= 1 && arr[n-1][m][k] == 0 ){
			push(n-1,m,k);
		}
		if( n < N-1 && arr[n+1][m][k] == 0 ){
			push(n+1,m,k);
		}
		if( m >= 1 && arr[n][m-1][k] == 0 ){
			push(n,m-1,k);
		}
		if( m < M-1 && arr[n][m+1][k] == 0 ){
			push(n,m+1,k);
		}
		if( k >= 1 && arr[n][m][k-1] == 0 ){
			push(n,m,k-1);
		}
		if( k < H-1 && arr[n][m][k+1] == 0 ){
			push(n,m,k+1);
		}
	}
	if( index == cnt ){
		printf("%d\n",day);
		return 0;
	} else if( start == index ){
		printf("-1\n");
		return 0;
	}
	bfs(tmp,day+1);
	return 0;
}

int main(){
	scanf("%d %d %d",&M,&N,&H);
	for( int k = 0; k < H; ++k ){
		for( int i = 0; i < N; ++i ){
			for( int j = 0; j < M; ++j ){
				int tmp;
				scanf("%d",&tmp);
				if( tmp == 1 ){
					cnt++;
					push(i,j,k);
				} else {
					if( tmp == 0 ){
						cnt++;
					}
					arr[i][j][k] = tmp;
				}
			}
		}
	}
	if( index == cnt ){
		printf("0\n");
	} else {
		bfs(0,1);
	}
}
