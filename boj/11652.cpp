#include<stdio.h>
#include<vector>
#include<algorithm>
std::vector<long long int> v;

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		long long int a;
		scanf("%lld",&a);
		v.push_back(a);
	}
	std::sort(v.begin(),v.end());
	long long int result = 0;
	long long int cnt = 1;
	long long int n = v[0];
	for( int i = 1; i < v.size(); ++i ){
		if( v[i] != v[i-1] ){
			cnt = 1;
		} else {
			++cnt;
		}
		if( cnt > result ){
			result = cnt;
			n = v[i];
		}
	}
	printf("%lld\n",n);
	return 0;
}
