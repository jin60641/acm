#include<stdio.h>
#include<vector>
#include<queue>
int N, M, in[1001];
std::vector<int> v[1001], result;
std::queue<int> q;
void f(){
	int now = q.front();
	for( int i = v[now].size() - 1; i >= 0; --i ){
		int next = v[now][i];
		if( --in[next] == 0 ){
			q.push(next);
		}
	}
}
int main(){
	scanf("%d %d",&N,&M);
	for( int i = 0; i < M; ++i ){
		int n;
		scanf("%d",&n);
		if( n == 0 ) continue;
		int first;
		scanf("%d",&first);
		for( int i = 1; i < n; ++i ){
			int next;
			scanf("%d",&next);
			++in[next];
			v[first].push_back(next);
			first = next;
		}
	}
	for( int i = 1; i <= N; ++i )
		if( in[i] == 0 )
			q.push(i);
	while( q.size() > 0 ){
		result.push_back(q.front());
		f();
		q.pop();
	}
	if( result.size() == N )
		for( int i = 0; i < result.size(); ++i )
			printf("%d\n",result[i]);
	else
		printf("0\n");
	return 0;
}
