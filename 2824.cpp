#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<map>
using namespace std;

int main(){
	int N, M;
	int *np;
	int *mp;
	int flag = 0;
	long long int result = 1;
	map<int,int> mymap;

	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int n;
		scanf("%d",&n);
		
		int tmp = n;
		for( int i = 2; i*i <= n; ++i ){
			while( tmp%i == 0 ){
				mymap[i]++;
				tmp /= i;
			}
		}
		if( tmp != 1 ){
			mymap[tmp]++;
		}
	}

	scanf("%d",&M);
	for( int i = 0; i < M; ++i ){
		int n;
		scanf("%d",&n);
		
		int tmp = n;
		for( int i = 2; i*i <= n; ++i ){
			while( tmp%i == 0 ){
				if( mymap[i] > 0 ){
					mymap[i]--;
					result *= i;
					if( result > 1000000000 ){
						result = result%1000000000;
						flag = 1;
					}
				}
				tmp /= i;
			}
		}
		if( tmp != 1 && mymap[tmp] > 0 ){
			result *= tmp;
			if( result > 1000000000 ){
				result = result%1000000000;
				flag = 1;
			}
		}
	}

	if( flag == 1 ){
		printf("%010lld\n",result);
	} else {
		printf("%lld\n",result);
	}
	return 0;
}


