#include<stdio.h>
#include<algorithm>
#define MAX_N 50
using namespace std;

int A[MAX_N*MAX_N][4] = {0,};
int B[MAX_N][MAX_N] = {0,};
int cnt[MAX_N*MAX_N] = {0,};
int check[MAX_N*MAX_N] = {0,};

int index, back_index,N,M;
int q[MAX_N*MAX_N];

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

int clear(){
	clearQueue();
	result_cnt = 0;
	for( int i = 0; i < MAX_N * MAX_N; ++i  ){
		cnt[i] = 0;
		check[i] = 0;
		for( int j = 0; j < 4; ++j ){
			A[i][j] = 0;
		}
	}
	for( int i = 0; i < MAX_N; ++i ){
		for( int j = 0; j < MAX_N; ++j ){
			B[i][j] = 0;
		}
	}
}


int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int K;
	    scanf("%d %d %d",&M, &N, &K);
		while( K-- ){
			int X,Y;
			scanf("%d %d",&X,&Y);
			B[Y][X] = 1;
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
		clear();
	}
    return 0;
}
