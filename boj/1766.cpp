#include<stdio.h>
#include<vector>
#include<queue>

struct cmp {
    bool operator()(int a, int b){
        return a > b;
    }
};
std::priority_queue<int,std::vector<int>,cmp> pq;
std::vector<int> v[32001];
int N,M, in[32001];

void f(){
	int now = pq.top();
	printf("%d ",now);
	pq.pop();
	for( int i = 0; i < v[now].size(); ++i ){
		int next = v[now][i];
		if( --in[next] == 0 ){
			pq.push(next);
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	for( int i = 0; i < M; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		++in[b];
		v[a].push_back(b);
	}
	for( int i = 1; i <= N; ++i ){
		if( in[i] == 0 ){
			pq.push(i);
		}
	}
	while( pq.size() > 0 ){
		f();
	}
	printf("\n");
	return 0;
}
