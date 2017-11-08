#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<map>
using namespace std;

map<long long int,long long int> mymap[105];
map<long long int,long long int> mymap2;

int main(){
	int N;
	long long int cnt = 0;
	long long int result = 1;

	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		long long int n;
		scanf("%d",&n);
		
		long long int tmp = n;
		for( long long int j = 2; j*j <= n; ++j ){
			while( tmp%j == 0 ){
				mymap[i][j]++;
				mymap2[j]++;
				tmp /= j;
			}
		}
		if( tmp != 1 ){
			mymap[i][tmp]++;
			mymap2[tmp]++;
		}
	}

	for( map<long long int,long long int>::iterator it = mymap2.begin(); it != mymap2.end(); ++it ){	
		long long int num = it->first;
		long long int avg = it->second/N;
		if( it->second >= N ){
			for( int i = 0; i < avg; ++i ){
				result *= num;
			}
		}
		for( long long int i = 0; i < N; ++i ){
			if( mymap[i][num] < avg ){
				cnt += avg - mymap[i][num];
			}
		}
	}
	printf("%lld %lld",result,cnt);
	
	return 0;
}


