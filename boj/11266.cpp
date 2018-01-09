#include<stdio.h>
#include<vector>
#include<stack>
using std::vector;
const int MAX_N = 100001;
vector<int> v[MAX_N];
vector< vector<int> > scc;
int N, M, num = 0, check[MAX_N], result[MAX_N], cnt = 0;
bool cmp(int a, int b){
	return a < b;
}
int min(int a, int b){
	return cmp(a, b) ? a : b;
}
int dfs(int now, int from){
	check[now] = ++num;
	int ret = check[now];
	int child = 0;
	for (int i = 0; i < v[now].size(); ++i){
		int next = v[now][i];
		if( check[next] ){
			if( next != from && check[next] < check[now] ){
				ret = min( ret, check[next] );
			}
		} else {
			++child;
			int d = dfs(next,now);
			if( d >= check[now] ){
				result[now] = 1;
			}
			ret = min( ret, d );
		}
	}
	if( ( from == 0 && child >= 2 ) ) {
		result[now] = 1;
	} else if (ret == MAX_N) {
		ret = check[now];
	}
	if( result[now] ){
		++cnt;
	}
	if (ret == check[now]) 	ret = check[from];
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		if (check[i] == 0 ) dfs(i, 0);
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= N; ++i){
		if (result[i]){
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}

