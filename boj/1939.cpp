#include<stdio.h>
#include<vector>
#include<queue>
int start,end;
struct edge { 
	int to,weight;
};
struct pair {
	int value,flow;
};
std::vector<edge> a[100001];
std::queue<pair> q;

int min(int a, int b){
	if( a == 0 ){
		return b;
	} else if( b == 0 ){
		return a;
	} else {
		return a<b?a:b;
	}
}

int check[100001];

int bfs(){
	pair now = q.front();
	int value = now.value;
	int flow = now.flow;
	if( check[value] > 0 && flow <= check[value] ){
		q.pop();
		return 0;
	}
	check[value] = flow;
	for( std::vector<edge>::iterator i = a[value].begin(); i != a[value].end(); ++i ){
		pair p;
		p.value = i->to;
		p.flow = min(flow,i->weight);
		q.push(p);
	}
	q.pop();
	return 0;
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for( int i = 0; i < M; ++i ){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		edge e1 = { B, C };
		edge e2 = { A, C };
		a[A].push_back(e1);
		a[B].push_back(e2);
	}
	scanf("%d %d",&start,&end);
	pair p = { start, 0 };
	q.push(p);
	while( q.size() > 0 ){
		bfs();
	}
	printf("%d\n",check[end]);
	return 0;
}
