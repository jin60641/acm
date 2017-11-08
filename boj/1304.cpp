#include<stdio.h>
const int MAX_N = 3000;
int root[MAX_N+1];
int check[MAX_N+1];

int find(int a){
	if( root[a] == a ){
		return a;
	}
	root[a] = find(root[a]);
	return root[a];
}

void Union(int a, int b){
	int ra = find(a), rb = find(b);
	if( ra != rb ){
		root[ra] = rb;
	}
}

int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	for( int i = 1; i <= N; ++i ){
		root[i] = i;
	}
	for( int i = 0; i < M; ++i ){
		int from, to;
		scanf("%d %d",&from,&to);
		if( from > to ){
			check[from] = 1;
		}
		for( int j = to; j < from; ++j ){
			check[j] = 1;
			Union(j,from);
		}
	}
	int min = N+1;
	for( int i = 1; i <= N; ++i ){
		find(i);
	}
	for( int i = 1; i <= N; ++i ){
		if( N%i > 0 ){
			continue;
		}
		int cnt = 1;
		int flag = 1;
		for( int j = 2; j <= N; ++j ){
			if( cnt == i ){
				if( check[j] == 0 || check[j-1] == 0 || root[j] != root[j-1] ){
					cnt = 1;
				} else {
					flag = 0;
					break;
				}
			} else if( cnt < i ){
				if( check[j] == 0 || check[j-1] == 0 || root[j] == root[j-1] ){
					++cnt;
				} else {
					flag = 0; 
					break;
				} 
			}
		}
		if( flag ){
			min = min<i?min:i;
		}
	}
	printf("%d\n",N/min);
	return 0;
}
