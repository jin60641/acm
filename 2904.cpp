#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<map>
using namespace std;

int main(){
	int N, M;
	int *np;
	int *mp;
	long long int result = 1;

	scanf("%d",&N);
	map<int,int> mymap[N];
	map<int,int> mymap2;
	map<int,int>::iterator mymap2;
	for( int i = 0; i < N; ++i ){
		int n;
		scanf("%d",&n);
		
		int tmp = n;
		for( int j = 2; j*j <= n; ++j ){
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
	
	for( int i = mymap2.begin() ; i != mymap2.end(); ++i  ){
		long long int a = e.second/N;
		if( a >= 1 ){
			result *= e.second*a;
		}
	}
	for( int i = 0; i < N; ++i ){
		for( auto& e : mymap[i] ){
		}
	}
	printf("%lld",result);
	
	return 0;
}


