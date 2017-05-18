#include<stdio.h>

int index = 0;
int arr[1000][1000];
int q[10000000];
int N,M;
int cnt = 0;

int push(int i,int j){
	if( arr[i][j] == 0 ){
		arr[i][j] = 1;
		q[index] = i*M+j;
		++index;
		return 0;
	}
}

int bfs(int start, int day ){
	int tmp = index;
	for( int i = start; i < tmp; ++i ){
		int n = q[i]/M;
		int m = q[i]%M;
		if( n >= 1 && arr[n-1][m] == 0 ){
			push(n-1,m);
		}
		if( n < N-1 && arr[n+1][m] == 0 ){
			push(n+1,m);
		}
		if( m >= 1 && arr[n][m-1] == 0 ){
			push(n,m-1);
		}
		if( m < M-1 && arr[n][m+1] == 0 ){
			push(n,m+1);
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
	scanf("%d %d",&M,&N);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < M; ++j ){
			int tmp;
			scanf("%d",&tmp);
			if( tmp == 1 ){
				cnt++;
				push(i,j);
			} else {
				if( tmp == 0 ){
					cnt++;
				}
				arr[i][j] = tmp;
			}
		}
	}
	if( index == cnt ){
		printf("0\n");
	} else {
		bfs(0,1);
	}
}
