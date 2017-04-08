#include<stdio.h>
using namespace std;

int A[100][100] = {0,};
int cnt[100] = {0,};
int check[100] = {0,};
int index = 0;
int back_index = 0;
int q[100];

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
	if( index>back_index ){
		printf("%d\n",back_index-1);
		return 0;
	}
	bfs();
	return 0;
}

int makeLine( int start, int end ){
	A[start][cnt[start]] = end;
	A[end][cnt[end]] = start;
	cnt[start]++;
	cnt[end]++;
	return 0;
}

int main(){
	int a,b,N,M;
	scanf("%d",&N);
	scanf("%d",&M);
	for( int i = 0; i < M; ++i ){
		scanf("%d %d",&a,&b);
		makeLine(a-1,b-1);
	}
	push(0);
	bfs();
	return 0;
}

