#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<int> y;
std::vector<int> n;
std::vector<int> ns[16];
std::vector<int> r;

bool cmp( int a, int b ){
	return a<b;
}

int main(){
	int N, P, a[16][16], sum = 0;
	char s[17];
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%s",s);
	for( int i = 0; i < N; ++i ){
		if( s[i] == 'Y' ){
			y.push_back(i);
		} else {
			n.push_back(i);
		}
	}
	scanf("%d",&P);
	for( int i = 0; i < n.size(); ++i ){
		for( int j = 0; j < y.size(); ++j ){
			ns[i].push_back( a[ y[j] ][ n[i] ] );
		}
	}
	for( int i = 0; i < n.size(); ++i ){
		r.push_back(*min_element(ns[i].begin(),ns[i].end()));
	}
	std::sort(r.begin(),r.end(),cmp);
	for( int i = 0; i < P-y.size(); ++i ){
		sum += r[i];
	}
	if( n.size() == N ){
		printf("%d\n",-1);
	} else {
		printf("%d\n",sum);
	}
	return 0;
}
