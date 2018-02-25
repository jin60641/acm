#include<stdio.h>
#include<vector>
#include<queue>
long long int min( long long int a, long long int b ){
	return a<b?a:b;
}
struct pair {
	long long int num,w;
};
std::vector<pair> v[100001];
struct cmp{
	bool operator()(pair a, pair b ){
		return a.w < b.w;
	}
};
std::priority_queue<pair,std::vector<pair>,cmp> q;
long long int cost[100001];
long long int d[100001], n,m;

long long int bfs(){
	pair now = q.top();
	q.pop();
	d[now.num] = now.w;
	m = min( m, now.w*2 + cost[now.num] );
	long long int len = v[now.num].size();
	for( long long int i = 0; i < len; ++i ){
		pair next = v[now.num][i];
		if( d[next.num] ){
			continue;
		}
		pair p = { next.num, next.w + now.w };
		q.push(p);
	}
	return 0;
}

long long int clear(){
	for( long long int i = 1; i <= n; ++i ){
		d[i] = 0;
	}
}

int main(){
	scanf("%lld %lld",&n,&m);
	for( long long int i = 0; i < m; ++i ){
		long long int a,b,w;
		scanf("%lld %lld %lld",&a,&b,&w);
		pair pa = { b, w };
		pair pb = { a, w };
		v[a].push_back(pa);
		v[b].push_back(pb);
	}
	for( long long int i = 1; i <= n; ++i ){
		scanf("%lld",&cost[i]);
	}
	for( long long int i = 1; i <= n; ++i ){
		pair start = {i,0};
		q.push(start);
		m = cost[i];
		while( !q.empty() ){
			bfs();
		}
		clear();
		printf("%lld ",m);
	}
	printf("\n");
	return 0;
}
