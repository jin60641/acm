#include<stdio.h>

int check[21];
int find( int a ){
	if( check[a] == a ){
		return a;
	}
	return find(check[a]);
}
int Union( int a, int b ){
	if( find(a) == find(b) ){
		return 0;
	}
	check[find(a)] = find(b);
	return 1;
}

int main(){
    int N;
    scanf("%d",&N);
	int a[21][21];
	int b[21][21];
    for( int i = 1; i <= N; ++i ){
		check[i] = i;
        for( int j = 1; j <= N; ++j ){
            scanf("%d",&a[i][j]);
			b[i][j] = a[i][j];
        }
    }
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			if( i == j ){
				continue;
			}
			for( int k = 1; k <= N; ++k ){
				if( k == i || k == j ){
					continue;
				}
				if( a[i][j] + a[j][k] == a[i][k] ){
					b[i][k] = 0;
					b[k][i] = 0;
				}
			}
		}
	}
	int result = 0;
	for( int i = 1; i <= N; ++i ){
		for( int j = i; j <= N; ++j ){
			if( b[i][j] != 0 ){
				Union(i,j);
				result += b[i][j];
			}
		}
	}
	int flag = find(1);
	for( int i = 2; i <= N; ++i ){
		if( find(i) != flag ){
			flag = -1;
			break;
		}
	}
	printf("%d\n",flag==-1?-1:result);
    return 0;
}


