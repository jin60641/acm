#include<stdio.h>
#include<vector>

std::vector<int> s[1000];
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int k;
		scanf("%d",&k);
		std::vector<int> v;
		for( int j = 0; j < k; ++j ){
			int a;
			scanf("%d",&a);
			v.push_back(a);
		}
		s[i] = v;
	}
	int M;
	scanf("%d",&M);
	for( int i = 0; i < M; ++i ){
		int p;
		scanf("%d",&p);
		int cnt = 0;
		int check[1000];
		for( int j = 0; j < N; ++j ){
			check[j] = 0;
		}
		for( int j = 0; j < p; ++j ){
			int a;
			scanf("%d",&a);
			for( int k = 0; k < N; ++k ){
				if( check[k] == s[k].size() ){
					continue;
				}
				for( int l = 0; l < s[k].size(); ++l ){
					if( s[k][l] == a ){
						++check[k];
						if( s[k].size() == check[k] ){
							++cnt;
						}
						break;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
