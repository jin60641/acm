#include<stdio.h>

int check[1000001];

int find( int a ){
	if( check[a] == -2 ){
		return -2;
	}
	if( check[a] == -1 ){
		return a;
	}
	check[a] = find( check[a] );
	return check[a];
}

int main(){
	int N,M;
	scanf("%d %d",&N, &M);
	for( int i = 0; i <= N; ++i ){
		check[i] = -2;
	}
	for( int i = 0; i < M; ++i ){
		int a,b,c;
		scanf("%d %d %d",&c,&a,&b);
		if( c == 1 ){
			if( a == b ){
				printf("YES\n");
			} else if( check[a] <= -1 && check[b] <= -1 ){
				printf("NO\n");
			} else if( check[a] == -1 && a == find(b) ){
				printf("YES\n");
			} else if( check[b] == -1 && b == find(a) ){
				printf("YES\n");
			} else if( find(a) == find(b) ){
				printf("YES\n");
			} else {
				printf("NO\n");
			}
			continue;
		}
		if( a == b ){
			continue;
		} else if( check[a] == -2 && check[b] == -2 ){
			check[b] = a; 
			check[a] = -1;
		} else if( check[a] == -2 && check[b] != -2 ){
			if( check[b] == -1 ){
				check[a] = b;
			} else {
				check[a] = find(b);
			}
		} else if( check[b] == -2 && check[a] != -2 ){
			if( check[a] == -1 ){
				check[b] = a;
			} else {
				check[b] = find(a);
			}
		} else if( check[a] != -2 && check[b] != -2 ){
			if( check[a] == -1 && check[b] == -1 ){
				check[b] = a;
			} else if( check[a] == -1 ){
				if( find(b) != a ){
					check[find(b)] = a;
				}
			} else if( check[b] == -1 ){
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
	return 0;
}
