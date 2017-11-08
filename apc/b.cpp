#include<stdio.h>

int check[999999];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int cas = 0;
	while( cas < T ){
		cas++;
		int N;
		scanf("%d",&N);
		int cnt = N;
		for( int i = 0; i < N-1; ++i ){
			check[i] = 0;
		}
		int M;
		scanf("%d",&M);
		for( int i = 0; i < M; ++i ){
			int x,y;
			scanf("%d %d",&x,&y);
			for( int j = x-1; j < y-1; ++j ){
				if( check[j] == 1 ){
					continue;
				}
				check[j] = 1;
				cnt--;
			}
		}
		printf("Case #%d\n",cas);
		printf("%d",cnt);
		printf("\n");
	}
	return 0;
}
