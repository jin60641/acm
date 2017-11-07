#include<stdio.h>
int N, M, r[201];
int find( int a ){
	if( r[a] == a ){
		return a;
	}
	r[a] = find(r[a]);
	return r[a];
};
int Union( int a, int b ){
	int ra = find(a);
	int rb = find(b);
	if( ra == rb ) return 0;
	r[ra] = rb;
	return 1;
}
int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	for( int i = 1; i <= N; ++i ) r[i] = i;
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			int connect;
			scanf("%d",&connect);
			if( connect ) Union(i,j);
		}
	}
	int flag = 1;
	int current;
	scanf("%d",&current);
	for( int i = 1; i <= N; ++i ){
		find(i);
	}
	for( int i = 1; i < M; ++i ){
		int next;
		scanf("%d", &next );
		if( r[current] != r[next] ){
			flag = 0;
			break;
		}
		current = next;
	}
	printf("%s\n",flag?"YES":"NO");
	return 0;
}
