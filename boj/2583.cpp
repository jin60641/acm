#include<stdio.h>
#include<algorithm>
#define MAX_N 100
using namespace std;

int A[MAX_N*MAX_N][4] = {0,};
int B[MAX_N][MAX_N] = {0,};
int cnt[MAX_N*MAX_N] = {0,};
int check[MAX_N*MAX_N] = {0,};
int index, back_index,N,M,K;
int q[MAX_N*MAX_N];
int result[MAX_N*MAX_N] = {0,};
int result_cnt = 0;

int clearQueue(){
	for( int i = 0; i < back_index; ++ i){
		q[i] = 0;
	}
	index = 0;
	back_index = 0;
}

int push(int num){
	q[back_index] = num;
	back_index++;
}

int bfs(){
	int back = q[index];
	int push_cnt = 0;
	for( int i = 0; i < cnt[back]; ++i ){
		if( check[A[back][i]] != 1 ){
			push(A[back][i]);
			check[A[back][i]] = 1;
			check[back] = 1;
			push_cnt++;
		}
	}
	index++;
	if( index > back_index ){
		result[result_cnt] = back_index;
		result_cnt++;
		return 0;
	}
	bfs();
	return 0;
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
	scanf("%d %d %d",&N,&M,&K);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < M; ++j ){
			B[i][j] = 1;
		}
	}
	for( int i = 0; i < K; ++i ){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for( int y = y1; y < y2; ++y ){
			for( int x = x1; x < x2; ++x ){
				B[y][x] = 0;
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

	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < M; ++j ){
			if( B[i][j] == 1 && check[j+i*M] == 0 ){
				clearQueue();
				push(j+i*M);
				bfs();
			}
		}
	}

	printf("%d\n",result_cnt);
	sort(result,result+result_cnt);
	for( int i = 0; i < result_cnt; ++i ){
		printf("%d ",result[i]);
	}
	printf("\n");
	return 0;
}

