#include<stdio.h>
#include<stdlib.h>
using namespace std;

int N;
int A[65][65];

int cut( int x1, int y1, int x2, int y2 ){
	int sum = 0;
	for( int i = x1; i <= x2; ++i ){
		for( int j = y1; j <= y2; ++j ){
			sum += A[j][i];
		}
	}
	if( sum == 0 ){
		printf("0");
	} else if( sum == (x2-x1+1)*(x2-x1+1) ){
		printf("1");
	} else {
		printf("(");
		cut( x1, y1 ,(x1+x2)/2, (y1+y2)/2 );
		cut( (x1+x2)/2+1, y1, x2, (y1+y2)/2 );
		cut( x1, (y1+y2)/2+1, (x1+x2)/2, y2 );
		cut( (x1+x2)/2+1, (y1+y2)/2+1, x2, y2 );
		printf(")");
	}
	return 0;
}

int main(){
	scanf("%d",&N);
	char C[65][65];
	for( int i = 0; i < N; ++i ){
		scanf("%s",C[i]);
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			if( C[i][j] == '1' ){
				A[i][j] = 1;
			} else {
				A[i][j] = 0;
			}
		}
	}
	cut(0,0,N-1,N-1);
	return 0;
}

