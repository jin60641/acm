#include<stdio.h>

int min( int a, int b ){
	return a==-1?b:(a<b?a:b);
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	char a[51][51];
	for( int i = 0; i < N; ++i ){
		scanf("%s",&a[i]);
	}
	int result = -1;
	for( int i = 0; i <= N-8; ++i ){
		for( int j = 0; j <= M-8; ++j ){
			char c;
			c = (i%2 + j%2)%2==0?'W':'B';
			int sum = 0;
			for( int k = 0; k < 8; ++k ){
				for( int l = 0; l < 8; ++l ){
					if( (k%2 + l%2)%2 == 0 && a[i+k][j+l] != c ){
						++sum;
					} else if( (k%2 + l%2)%2 == 1 && a[i+k][j+l] == c ){
						++sum;
					}
				}
			}
			result = min( result, min( 64-sum, sum ) );
		}
	}
	printf("%d\n",result);
	return 0;
}
