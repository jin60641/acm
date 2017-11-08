#include<stdio.h>
#include<vector>
using namespace std;

const int MAX_N = 100000;
long long int MAX = 0;
struct edge_t
{
	int v;
	int w;
public:
	edge_t(int v, int w) : v(v), w(w) {}
};

vector<edge_t> tree[MAX_N];

long long int dfs(int index, int from, int from_idx ){
	if( tree[index].size() == 1 && from != -1 ){
		return from;
	}
	long long int max1 = 0;
	long long int max2 = 0;
	for( int i = 0; i < tree[index].size(); ++i ){
		if( tree[index][i].v == from_idx ){
			continue;
		}
		long long int a = dfs( tree[index][i].v, tree[index][i].w, index );
		if( a > max1 ){
			max2 = max1;
			max1 = a;
		} else if( a > max2 ){
			max2 = a;
		}
	}
	
	if( max1 + max2 > MAX ){
		MAX = max1 + max2;
	}
	if( from_idx == -1 ){
		return 0;
	} else {
		if( max1 + from > MAX ){
			MAX = max1+from;
		}
		return max1 + from;
	}
}


int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int num;
		scanf("%d",&num);
		while(true){
			int a,b;
			scanf("%d",&a);
			if( a == -1 ){
				break;
			}
			scanf("%d",&b);
			tree[num-1].push_back({a-1, b});
		}
	}
	dfs(0,-1,-1);
	printf("%lld",MAX);
	
	return 0;
}
