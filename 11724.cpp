#include<stdio.h>

int check[1001];

int find( int a ){
	if( check[a] == 0 ){
		return a;
	}
	check[a] = find( check[a] );
	return check[a];
}

int main(){
	int N,M;
	scanf("%d %d",&N, &M);
	for( int i = 1; i <= N; ++i ){
		check[i] = -1;
	}
	for( int i = 0; i < M; ++i ){
		int a,b;
		scanf("%d %d",&a,&b);
		if( check[a] == -1 && check[b] == -1 ){
			check[b] = a; 
			check[a] = 0;
		} else if( check[a] == -1 && check[b] != -1 ){
			if( check[b] == 0 ){
				check[a] = b;
			} else {
				check[a] = find(b);
			}
		} else if( check[b] == -1 && check[a] != -1 ){
			if( check[a] == 0 ){
				check[b] = a;
			} else {
				check[b] = find(a);
			}
		} else if( check[a] != -1 && check[b] != -1 ){
			if( check[a] == 0 && check[b] == 0 ){
				check[b] = a;
			} else if( check[a] == 0 ){
				if( find(b) != a ){
					check[find(b)] = a;
				}
			} else if( check[b] == 0 ){
				if( find(a) != b ){
					check[find(a)] = b;
				}
			} else if( find(a) == find(b) ){
				continue;
			} else {
				check[find(b)] = find(a);
			}
		}
	}
	int cnt = 0;
	for( int i = 1; i <= N; ++i ){
		if( check[i] <= 0 ){
			++cnt;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
