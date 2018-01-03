#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
int INF = 10001;
int min( int a, int b ){
	return a<b?a:b;
}
bool cmp( int a, int b ){
	return a<b;
}
bool cmp2( std::vector<int> a, std::vector<int> b ){
	return a[0] < b[0];
}
std::vector<int> v[10001];
std::vector< std::vector<int> > scc;
std::stack<int> s;
int check[10001], num = 0;
int dfs( int now, int from ){
	check[now] = ++num;
	int ret = INF;
	s.push(now);
	for( int i = 0; i < v[now].size(); ++i ){
		ret = check[ v[now][i] ]?min( ret, check[ v[now][i] ] ):min( ret, dfs(v[now][i],now) );
	}
	if( ret == INF ) ret = check[now];
	if( ret == check[now] ){
		std::vector<int> tmp;
		do {
			tmp.push_back(s.top());
			check[s.top()] = INF;
			s.pop();
		} while( tmp.back() != now );
		scc.push_back(tmp);
		ret = check[from];
	} 
	return ret;
}
int main(){	
	int V, E;
	scanf("%d %d",&V,&E);
	for( int i = 0; i < E; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
	}
	for( int i = 1; i <= V; ++i ){
		if( check[i] == 0 ){
			dfs(i,0);
		}
	}
	printf("%d\n",scc.size());
	for( int i = 0; i < scc.size(); ++i ){
		std::sort(scc[i].begin(),scc[i].end(),cmp);
	}
	std::sort(scc.begin(),scc.end(),cmp2);
	for( int i = 0; i < scc.size(); ++i ){
		for( int j = 0; j < scc[i].size(); ++j ){
			printf("%d ",scc[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}
