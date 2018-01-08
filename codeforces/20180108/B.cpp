#include<stdio.h>
#include<vector>

int n;
std::vector<int> v[1001];
int main(){
	scanf("%d",&n);
	for( int i = 2; i <= n; ++i ){
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
	}
	for( int i = 1; i <= n; ++i ){
		int size = v[i].size();
		if( size != 0 ){
			int cnt = 0;
			for( int j = size-1; j >= 0; --j ){
				int next = v[i][j];
				int nsize = v[next].size();
				if( nsize == 0 ){
					++cnt;
				}
			}
			if( cnt < 3 ){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}
