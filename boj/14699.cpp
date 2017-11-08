#include<stdio.h>
#include<vector>
#include<queue>

struct spot{
	int height, in, cnt;
	std::vector<int> to;
};
int max(int a, int b){
	return a>b?a:b;
}
int N, M;	
spot v[5001];
struct cmp{
	bool operator()(int a, int b ){
		return v[a].height < v[b].height;
	}
};
std::priority_queue<int,std::vector<int>,cmp> q;
void f(){
	int now = q.top();
	q.pop();
	for( int i = v[now].to.size() - 1; i >= 0; --i ){
		int next = v[now].to[i];
		v[next].cnt = max(v[now].cnt+1,v[next].cnt);
		if( --v[next].in == 0 ){
			q.push(v[now].to[i]);
		}
	}
}
int main(){
	scanf("%d %d",&N,&M);
	for( int i = 1; i <= N; ++i ){
		scanf("%d",&v[i].height);
	}
	for( int i = 1; i <= M; ++i ){
		int from, to, tmp;
		scanf("%d %d",&from,&to);
		if( v[from].height < v[to].height ){
			tmp = from;
			from = to;
			to = tmp;
		}
		v[from].to.push_back(to);
		++v[to].in;
	}
	for( int i = 1; i <= N; ++i ){
		if( v[i].in == 0 ){
			q.push(i);
		}
	}
	while( q.size() > 0 ){
		f();
	}
	for( int i = 1; i <= N; ++i ){
		printf("%d\n",v[i].cnt+1);
	}
	return 0;
}
