#include<stdio.h>
#include<algorithm>
int main(){
	int N;
	scanf("%d",&N);
	long long int a[100000];
	for( int i = 0; i < N; ++i ){
		scanf("%lld",&a[i]);
	}
	std::sort(a,a+N);
	long long int cnt = N;
	long long int result = 0;
	for( int i = 0; i < N; ++i ){
		result = result<a[i]*cnt?a[i]*cnt:result;
		--cnt;
	}
	printf("%lld\n",result);
	return 0;
}
