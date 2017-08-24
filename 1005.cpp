#include<stdio.h>
#include<vector>
#include<queue>

int N, K, in[1001],weight[1001],time[1001];
std::vector<int> v[1001];
void clear(){
	for( int i = 1; i <= 1000; ++i ){
		v[i].clear();
		in[i] = 0;
		weight[i] = 0;
		time[i] = 0;
	}
}
int max(int a, int b){
	return a>b?a:b;
}
std::queue<int> q;
int f(){
	int now = q.front();
	for( int i = 0; i < v[now].size(); ++i ){
		int next = v[now][i];
		--in[next];
		weight[next] = max( weight[next], weight[now] + time[now] );
		if( in[next] == 0 ){
			q.push(next);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		clear();
		scanf("%d %d",&N,&K);
		for( int i = 1; i <= N; ++i ){
			scanf("%d",&time[i]);
		}
		for( int i = 0; i < K; ++i ){
			int a, b;
			scanf("%d %d",&a,&b);
			++in[b];
			v[a].push_back(b);
		}
		int W;
		scanf("%d",&W);
		for( int i = 1; i <= N; ++i ){
			if( in[i] == 0 ){
				q.push(i);
			}
		}
		while( q.size() > 0 ){
			f();
			q.pop();
		}
		printf("%d\n",weight[W] + time[W]);
	}
	return 0;
}
