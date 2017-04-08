#include<stdio.h>
using namespace std;

int A[100][100] = {0,};
int cnt[100] = {0,};
int check[100] = {0,};
int index = 0;
int back_index = 0;
int q[100];
int depth[100];
int target;

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
		if( A[back][i] == target ){
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
	if( index>back_index ){
		printf("-1");
		return 0;
	}
	int result = bfs();
	if( result == 1 ){
		return 1;
	} else {
		return 0;
	}
}

int makeLine( int start, int end ){
	A[start][cnt[start]] = end;
	A[end][cnt[end]] = start;
	cnt[start]++;
	cnt[end]++;
	return 0;
}

int main(){
	int start,a,b,N,M;
	scanf("%d",&N);
	scanf("%d %d",&start,&target);
	target--;
	start--;
	scanf("%d",&M);
	for( int i = 0; i < M; ++i ){
		scanf("%d %d",&a,&b);
		makeLine(a-1,b-1);
	}
	push(start,0);
	bfs();
	return 0;
}

