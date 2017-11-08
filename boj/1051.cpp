#include<stdio.h>

int max( int a, int b ){
	return a<b?b:a;
}
int main(){
	int N,M;
	char a[51][51];
	int result = 1;
	scanf("%d %d",&N,&M);
	for( int i = 0; i < N; ++i ){
		scanf("%s",&a[i]);
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < M; ++j ){
			int k = 1;
			int tmp = 1;
			while( i+k < N && j+k < M ){
				if( a[i][j] == a[i+k][j] && a[i][j] == a[i][j+k] && a[i][j] == a[i+k][j+k] ){
					tmp = k+1;
				}
				++k;
			}
			result = max( result, tmp );
		}
	}
	printf("%d\n",result*result);
	return 0;
}
