#include<stdio.h>

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
		int s[10000];
		int c[10000];
		int l[10000];
		int smax = -1;
		int s_index[10000];
		int s_cnt = 0;
		int cmin = 100000;
		int c_index[10000];
		int c_cnt = 0;
		int lmin = 1000000;
		for( int i = 0; i < N; ++i ){
			scanf("%d %d %d",&s[i],&c[i],&l[i]);
			if( s[i] > smax ){
				smax = s[i];
			}
		}
		for( int i = 0; i < N; ++i ){
			if( s[i] == smax ){
				s_index[s_cnt++] = i;
			}
		}
		if( s_cnt == 1 ){
			printf("Case #%d\n",cas);
			printf("%d\n",s_index[0]+1);
		} else {
			for( int i = 0; i < s_cnt; ++i ){
				if( c[s_index[i]] < cmin ){
					cmin = c[s_index[i]];
				}
			}
			for( int i = 0; i < s_cnt; ++i ){
				if( c[s_index[i]] == cmin ){
					c_index[c_cnt++] = s_index[i];
				}
			}
			if( c_cnt == 1 ){
				printf("Case #%d\n",cas);
				printf("%d\n",c_index[0]+1);
			} else{
				printf("Case #%d\n",cas);
				int result;
				for( int i = 0; i < c_cnt; ++i ){
					if( l[c_index[i]] < lmin ){
						lmin = l[c_index[i]];
						result = c_index[i];
					}
				}
				printf("%d\n",result+1);
			}
		}
	}
	return 0;
}
