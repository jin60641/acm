#include<stdio.h>
#include<vector>
#include<queue>

std::queue<int> q;
std::vector<int> E[32001];
int in[32001];

int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	for( int i = 1; i <= M; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		E[a].push_back(b);
		++in[b];
	}
	for( int i = 1; i <= N; ++i ){
		if( in[i] == 0 ){
			q.push(i);
		}
	}
	while( q.size() > 0 ){
		int num = q.front();
		printf("%d ",num);
		for( int i = 0; i < E[num].size(); ++i ){
			--in[ E[num][i] ];
			if( in[ E[num][i] ] == 0 ){
				q.push( E[num][i] );
			}
		}
		q.pop();
	}
	return 0;
}
