#include<stdio.h>
#include<vector>


int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int A,B,N;
		scanf("%d %d %d",&A,&B,&N);
		std::vector<int> v;
		for( int i = 2; i*i <= N; ++i ){
			if( N%i == 0 ){
				v.push_back(i);
			}
		}
		int check[1000000000000000];
		for( int i = A; i <= B; ++i ){
		}
	}
}
