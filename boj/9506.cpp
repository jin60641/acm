#include<stdio.h>
#include<vector>
#include<algorithm>

int main(){
	while( true ){
		int n, sum = 1;
		scanf("%d",&n);
		if( n == -1 ){
			return 0;
		}
		std::vector<int> v;
		for( int i = 2; i*i <= n; ++i ){
			if( n%i == 0 ){
				v.push_back(i);
				sum += i;
				if( i != n/i ){
					v.push_back(n/i);
					sum += n/i;
				}
			}
		}
		std::sort(v.begin(),v.end());
		if( sum != n ){
			printf("%d is NOT perfect.\n",n);
		} else {
			printf("%d = 1",n);
			for( int i = 0; i < v.size(); ++i ){
				printf(" + %d",v[i]);
			}
			printf("\n");
		}
	}
}
