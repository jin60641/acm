#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> check[6];

int main(){
	int N,P;
	scanf("%d %d",&N,&P);
	long long int tot = 0;
	for( int i = 0; i < 6; ++i ){
		vector<int> v;
		v.push_back(0);
		check[i] = v;
	}
	for( int i = 0; i < N; ++i ){
		int n,p;
		scanf("%d %d",&n,&p);
		--n;
		if( p < check[n].back() && ( find(check[n].begin(),check[n].end(),p) == check[n].end() ) ){
			while( p < check[n].back() ){
				check[n].pop_back();
				++tot;
			}
		}
		if( p > check[n].back() ){
			check[n].push_back(p);
			++tot;
		}
	printf("%lld\n",tot);
	}
	printf("%lld\n",tot);
}
