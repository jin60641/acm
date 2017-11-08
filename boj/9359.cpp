#include<stdio.h>
#include<vector>

long long int check[50010];
int main(){
	long long int T;
	scanf("%lld",&T);
	std::vector<long long int> p;
	for( long long int i = 2; i <= 50000; ++i ){
		if( check[i] == 1 ){
			continue;
		}
		p.push_back(i);
		for( long long int j = i*2; j <= 50000; j += i ){
			check[j] = 1;
		}
	}
	long long int t = 0;
	while( t++ < T ){
		long long int A,B,N;
		scanf("%lld %lld %lld",&A,&B,&N);
		std::vector<long long int> f;
		long long int n = N;
		for( long long int i = 0; i < p.size(); ++i ){
			if( n <= 1 || N < p[i] ){
				break;
			}
			if( n%p[i]==0 ){
				while( n%p[i] == 0 ){
					n /= p[i];
				}
				f.push_back(p[i]);
			}
		}
		if( n != 1LL ){
			f.push_back(n);
		}
		long long int tot = 0;
		for( long long int bit = 1; bit < (1LL<<f.size()); ++bit ){
			long long int num = 1;
			long long int flag = -1;
			for( long long int j = 0; j < f.size(); ++j ){
				if( bit & (1LL<<j) ){
					flag *= -1;
					num *= f[j];
				}
			}
			tot += (B/num-(A-1)/num) * flag;
		}
		printf("Case #%lld: %lld\n",t,B-(A-1)-tot);
	}
	return 0;
}
