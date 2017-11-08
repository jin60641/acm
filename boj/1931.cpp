#include<stdio.h>
#include<algorithm>
#include<vector>

struct pair {
	int start, end;
};

int cmp( pair a, pair b ){
	return a.start==b.start?(a.end<b.end):(a.start<b.start);
}

int main(){
	int n, cnt = 1;
	scanf("%d",&n);
	std::vector<pair> v;
	for( int i = 0; i < n; ++i ){
		pair p;
		scanf("%d %d", &p.start, &p.end );
		v.push_back(p);
	}
	std::sort(v.begin(),v.end(),cmp);
	pair now = v[0];
	for( int i = 1; i < n; ++i ){
		if( now.end <= v[i].start ){
			now = v[i];
			++cnt;
		} else if( now.start <= v[i].start && v[i].end <= now.end ){
			now = v[i];
		}
	}
	printf("%d\n",cnt);
	return 0;
}
