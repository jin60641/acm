#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
int A[1001][10001] = {};
int cnt[1001] = {0,};
int check[1001] = {0,};
int cnt2 = 0;
int q[1001];

int push(int num){
	q[cnt2] = num;
	cnt2++;
}

int dfs(int start){
	if( check[start] == 1 ){
		return 0;
	}
	check[start] = 1;
	printf("%d ",start);
	for( int i = 0; i < cnt[start]; ++i ){
		dfs(A[start][i]);
	}
	return 0;
}

int bfs(int index){
	int back = q[index];
	for( int i = 0; i < cnt[back]; ++i ){
		if( check[A[back][i]] != 1 ){
			push(A[back][i]);
			check[A[back][i]] = 1;
			check[back] = 1;
		}
	}
	
	if( q[index+1] != 0 ){
		bfs(index+1);
	}
	return 0;
}

int main(){
	int N,M,V;
	scanf("%d %d %d",&N,&M,&V);
	for( int i = 0; i < M; ++i ){
		int start,end;
		scanf("%d %d",&start,&end);
		A[start][cnt[start]] = end;
		A[end][cnt[end]] = start;
		cnt[start]++;
		cnt[end]++;
	}
	for( int i = 1; i <= N; ++i ){
		sort( A[i], A[i] + cnt[i] );
	}
	dfs(V);
	for( int i = 0; i <= 1000; ++i ){
		check[i] = 0;
	}
	printf("\n");
	push(V);
	bfs(0);
	for( int i = 0; i < N; ++i ){
		printf("%d ",q[i]);
	}
	printf("\n");
	return 0;
}

