#include<stdio.h>
#include<queue>
std::queue<int> q;
int main(){
	long long int a[2][2] = { { 1, 1 }, { 1, 0 } };
	long long int b[2][2] = { { 1, 1 }, { 1, 0 } };
	long long int n;
	scanf("%lld",&n);
	while( n > 0 ){
		int r = n%2;
		q.push(r);
		n/=2;
	}
	int cnt = 1;
	while( q.size() > 0 ){
		long long int tmp[2][2] = { { 0, 0 }, { 0, 0 } };
		if( q.front() == 1 ){
			for( int i = 0; i < 2; ++i ){
				for( int k = 0; k < 2; ++k ){
					for( int j = 0; j < 2; ++j ){
						tmp[i][k] += (b[i][j] * a[j][k])%1000000;
					}
				}
			}
			for( int i = 0; i < 2; ++i ){
				for( int j = 0; j < 2; ++j ){
					b[i][j] = tmp[i][j]%1000000;
				}
			}
		}
		long long int tmp2[2][2] = { { 0, 0 }, { 0, 0 } };
		for( int i = 0; i < 2; ++i ){
			for( int k = 0; k < 2; ++k ){
				for( int j = 0; j < 2; ++j ){
					tmp2[i][k] += (a[i][j] * a[j][k])%1000000;
				}
			}
		}
		for( int i = 0; i < 2; ++i ){
			for( int j = 0; j < 2; ++j ){
				a[i][j] = tmp2[i][j]%1000000;
			}
		}
		q.pop();
	}
	printf("%lld\n",b[1][1]%1000000);
	return 0;
}
