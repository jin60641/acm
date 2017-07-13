#include<stdio.h>
#include<vector>

struct pair {
	int p,c;
};

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N, M;
		scanf("%d %d",&N,&M);
		std::vector<pair> v;
		for( int i = 0; i < N; ++i ){
			pair s;
			s.c = i;
			scanf("%d",&s.p);
			v.push_back(s);
		}
		
		int start = 0;
		int end = N;
		for( int i = 0; i < end; ++i ){
			for( int j = i+1; j < end; ++j ){
				if( v[i].p < v[j].p ){
					for( ; i < j; ++i ){
						++end;
						pair s = { v[i].p, v[i].c };
						v[i].c = -1;
						v.push_back(s);
					}
					--i;
					break;
				}
			}
		}
		int cnt = 0;
		for( int j = 0; j < end; ++j ){
			if( v[j].c == -1 ){
				continue;
			}
			++cnt;
			if( v[j].c == M ){
				printf("%d\n",cnt);
			}
		}
	}
}
