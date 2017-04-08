#include<stdio.h>
#define MAX_N 100
using namespace std;

int A[MAX_N*MAX_N][4] = {0,};
int B[MAX_N][MAX_N] = {0,};
int cnt[MAX_N*MAX_N] = {0,};
int check[MAX_N*MAX_N] = {0,};
int index = 0;
int back_index = 0;
int q[MAX_N*MAX_N];
int depth[MAX_N*MAX_N];
int N,M;
int push(int num,int d){
	q[back_index] = num;
	depth[back_index] = d;
	back_index++;
}

int bfs(){
	int back = q[index];
	int d = depth[index];
	int push_cnt = 0;
	for( int i = 0; i < cnt[back]; ++i ){
		if( A[back][i] == M*N-1 ){
			printf("%d\n",d+1);
			return 1;
		} else if( check[A[back][i]] != 1 ){
			push(A[back][i],d+1);
			check[A[back][i]] = 1;
			check[back] = 1;
			push_cnt++;
		}
	}
	index++;
	int result = bfs();
	if( result == 1 ){
		return 1;
	} else {
		return 0;
	}
}
int makeLine( int x1, int y1, int x2, int y2 ){
	if( B[y1][x1] == 1 && B[y2][x2] == 1 ){
		int start = x1+y1*M;
		int end = x2+y2*M;
		A[start][cnt[start]] = end;
		cnt[start]++;
	}
	return 0;
}

int main(){
	scanf("%d %d",&N,&M);
	char C[MAX_N][MAX_N];
	for( int i = 0; i < N; ++i ){
		scanf("%s",C[i]);
		for( int j = 0; j < M; ++j ){
			if( C[i][j] == '1' ){
				B[i][j] = 1;
			} else {
				B[i][j] = 0;
			}
		}
	}
	 for( int i = 0; i < N; ++i ){
		for( int j = 0; j < M; ++j ){
			int x = j;
			int y = i;
			if( y != 0 ){
				makeLine(x,y,x,y-1);
			}
			if( x != 0 ){
				makeLine(x,y,x-1,y);
			}
			if( x != M-1 ){
				makeLine(x,y,x+1,y);
			}
			if( y != N-1 ){
				makeLine(x,y,x,y+1);
			}
		}
	}

	push(0,1);
	bfs();

	return 0;
}

