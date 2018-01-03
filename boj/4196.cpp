#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
using std::vector; 
const int MAX_N = 100001;

vector<int> v[MAX_N];
vector<int> path[MAX_N];
vector< vector<int> > scc;
std::stack<int> s;
std::queue<int> q;
int N, M, num = 0, check[MAX_N], area[MAX_N], in[MAX_N];

int min( int a, int b ){
	return a<b?a:b;
}

int clear(){
	for( int i = 1; i<= N; ++i ){
		v[i].clear();
		check[i] = 0;
		in[i] = 0;
		area[i] = 0;
		path[i].clear();
	}
	scc.clear();
	num = 0;
}

int dfs( int now, int from){
	check[now] = ++num;
	s.push(now);
	int ret = MAX_N;
	for( int i = 0; i < v[now].size(); ++i ){
		int next = v[now][i];
		if( check[next] ){
			ret = min( ret, check[next] );
		} else {
			ret = min( ret, dfs(next,now) );
		}
	}
	if( ret == MAX_N ) ret = check[now];
	if( ret == check[now] ){
		vector<int> tmp;
		do {
			tmp.push_back(s.top());
			area[s.top()] = scc.size()+1;
			check[s.top()] = MAX_N;
			s.pop();
		} while( tmp.back() != now );
		scc.push_back(tmp);
		ret = check[from];
	}
	return ret;
}

void bfs(){
	int now = q.front();
	q.pop();
	for( int i = 0; i < path[now].size(); ++i ){
		int next = path[now][i];
		if( check[next] == 0 ){
			check[next] = 1;
			q.push(next);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int result = 0;
		scanf("%d %d", &N, &M);
		for( int i = 0; i < M; ++i ){
			int a, b;
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
		}
		for( int i = 1; i <= N; ++i ){
			if( check[i] == 0 ){
				dfs(i,0);
			}
		}
		for( int i = 1; i <= N; ++i ){
			for( int j = 0; j < v[i].size(); ++j ){
				if( area[i] != area[ v[i][j] ] ) {
					path[ area[i] ].push_back( area[ v[i][j] ] );
					++in[ area[ v[i][j] ] ];
				}
			}
		}
		for( int i = 1; i <= N; ++i ){
			check[i] = 0;
		}
		for( int i = 1; i <= scc.size(); ++i ){
			if( in[i] == 0 && check[i] == 0 ){
				++result;
				q.push(i);
				check[i] = 1;
				while( !q.empty() ){
					bfs();
				}
			}
		}
		printf("%d\n",result);
		clear();
	}
}
