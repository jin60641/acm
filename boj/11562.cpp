#include<stdio.h>
const int INF = 300;
int arr[251][251];
int min( int a, int b ){
	return a<b?a:b;
}
int main(){
	int n, m, k;
	scanf("%d %d",&n,&m);
	for( int i = 1; i <= n; ++i ){
		for( int j = 1; j <= n; ++j ){
			arr[i][j] = INF;
		}
	}
	for( int i = 0; i < m; ++i ){
		int u,v,b;
		scanf("%d %d %d",&u,&v,&b);
		arr[u][v] = 0;
		arr[v][u] = min(arr[v][u],b==1?0:1);
	}
	for( int i = 1; i <= n; ++i ){
		for( int j = 1; j <= n; ++j ){
			if( i == j ){
				continue;
			}
			for( int k = 1; k <= n; ++k ){
				if( j == k || i == k ){
					continue;
				}
				if( arr[j][i] != INF && arr[i][k] != INF ){
					arr[j][k] = min( arr[j][k], arr[j][i] + arr[i][k] );
				}
			}
		}
	}
	scanf("%d",&k);
	for( int i = 0; i < k; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		printf("%d\n",a==b?0:arr[a][b]);
	}
	return 0;
}
