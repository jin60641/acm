#include<stdio.h>
#include<vector>
#include<queue>

int n, m, start, end, cnt = 0;
struct pair{
	int to, cost;
};
struct city{
	int in, cost, check;
	std::vector<pair> out, back;
};
std::vector<city> v(10001);
std::queue<int> q;

void forward(){
	city now = v[q.front()];
	for( int i = now.out.size() - 1; i >= 0; --i ){
		pair e = now.out[i];
		pair back = { q.front(), e.cost };
		if( now.cost + e.cost > v[e.to].cost ){
			v[e.to].back.clear();
			v[e.to].back.push_back( back );
			v[e.to].cost = now.cost + e.cost;
		} else if( now.cost + e.cost == v[e.to].cost ){
			v[e.to].back.push_back( back );
		}
		if( --v[e.to].in == 0 ){
			q.push(e.to);
		}
	}
}

void reverse(){
	city now = v[q.front()];
	for( int i = now.back.size() - 1; i >= 0; --i ){
		pair e = now.back[i];
		++cnt; 
		if( v[e.to].check == 0 ){
			v[e.to].check = 1;
			q.push(e.to);
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for( int i = 0; i < m; ++i ){
		int from, to, cost;
		scanf("%d %d %d",&from,&to,&cost);
		pair e = { to, cost };
		v[from].out.push_back(e);
		++v[to].in;
	}
	scanf("%d %d",&start,&end);
	q.push(start);
	while( q.size() > 0 ){
		forward();
		q.pop();
	}
	q.push(end);
	while( q.size() > 0 ){
		reverse();
		q.pop();
	}
	printf("%d\n%d\n",v[end].cost,cnt);
	return 0;
}
