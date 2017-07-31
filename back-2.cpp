#include<stdio.h>


int main(){
	while( true ){
		int N,M;
		int a[100][100];
		int check[100][100];
		for( int i = 0; i < 100; ++i ){
			for( int j = 0; j < 100; ++j ){
				a[i][j] = 0;
				check[i][j] = 0;
			}
		}
		scanf("%d %d",&N,&M);
		if( N == 0 && M == 0 ){
			break;
		}
		while( M-- > 0 ){
			char c = getchar();
			if( c == '!' ){
				int A,B,W;
				scanf("%d %d %d",&A,&B,&W);
				if( A < B ){
					a[A-1][B-1] = W;
					check[A-1][B-1] = 1;
				} else {
					a[B-1][A-1] = -W;
					check[B-1][A-1] = 1;
				}
			} else if( c == '?' ){
				int flag = 1;
				while( flag == 1 ){
					flag = 0;
					for( int i = 0; i < N; ++i ){
						for( int j = 0; j < N; ++j ){
							if( check[i][j] == 1 ){
								for( int k = N-1; k > j; --k ){
									if( check[j][k] == 1 && check[i][k] == 0 ){
										flag = 1;
										a[i][k] = a[i][j] + a[j][k];
										check[i][k] = 1;
									}
								}
							}
						}
					}
				}
				int A,B;
				scanf("%d %d",&A,&B);
				if( A < B && check[A-1][B-1] >= 1 ){
					printf("%d\n",a[A-1][B-1]);
				} else if( A > B && check[B-1][A-1] >= 1 ){
					printf("%d\n",-a[B-1][A-1]);
				} else {
					printf("UNKNOWN\n");
				}
			} else {
				++M;
			}
		}
	}
}
