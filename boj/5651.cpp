#include<stdio.h>

int N,M;
int check[301];
int q[301];
int index = 0;
int bfs_index = 0;
int weight[301][301];

int push( int a ){
	printf("push : %d\n",a);
	q[index++] = a;
}

int bfs(){
	int now = q[bfs_index];
	bfs_index++;
	if( check[now] == 1 ){
		bfs();
		return 0;
	}
	if( now == N ){
		return 0;
	}
	check[now] = 1;
	for( int i = 1; i <= N; ++i ){
		if( weight[now][i] != 0 && check[i] == 0 ){
			push(i);
		}
	}
	bfs();
	return 0;
}

int clear(){
	for( int i = 0; i < N; ++i ){
		check[i] = 0;
		q[i] = 0;
		for( int j = 0; j < N; ++j ){
			weight[i][j] = 0;
		}
	}
	bfs_index = 0;
	return 0;
}

int main(){
	int K;
	scanf("%d",&K);
	while( --K >= 0 ){
		scanf("%d %d",&N,&M);
		for( int i = 0; i < M; ++i ){
			int f,t,b;
			scanf("%d %d %d",&f,&t,&b);
			weight[f][t] = b;
		}
		push(1);
		bfs();
		for( int i = 0; i < bfs_index; ++i ){
			printf("%d ",&q[i]);
		}
		printf("\n");
	}
	return 0;
}
