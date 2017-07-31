#include<stdio.h>

long long int weight[100001];
long long int check[100001];

long long int find(long long int a ){
	if( check[a] == a ){
		return a;
	}
	long long int tmp = find(check[a]);
	weight[a] += weight[check[a]];
	check[a] = tmp;
	return check[a];
}

long long int Union( long long int a, long long int b, long long int w ){
	if( find(a) == find(b) ){
		return 0;
	}
	weight[find(a)] += weight[b] - w;
	check[find(a)] = find(b);
	return 1;
}

int clear(){
	for( int i = 0; i <= 100000; ++i ){
		check[i] = i;
		weight[i] = 0;
	}
	return 0;
}

int main(){
	while( true ){
		clear();
		int N,M;
		scanf("%d %d",&N,&M);
		if( N == 0 && M == 0 ){
			break;
		}
		clear();
		while( M-- > 0 ){
			char c = getchar();
			if( c == '!' ){
				long long int A,B,W;
				scanf("%lld %lld %lld",&A,&B,&W);
				Union(A,B,W);
			} else if( c == '?' ){
				long long int A,B;
				scanf("%lld %lld",&A,&B);
				if( find(A) == find(B) ){
					printf("%lld\n",weight[B]-weight[A]);
				} else {
					printf("UNKNOWN\n");
				}
			} else {
				++M;
			}
		}
	}
}
