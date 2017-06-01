#include<stdio.h>

int s[12];
int check[2000][6];
int K = 0;
int max;

int c(int l, int r){
	if( l < 0 || r < 0 || l < r){
		return 0;
	}
	if( l-r < r ){
		r = l-r;
	}
	double result = 1;
	for( int i = 0; i < r; ++i ){
		result = result*(l-i)/(r-i);
	}
	return (int)(result+1e-9);
}

int fill( int start, int weight, int index ){
	int cnt = 0;
	for( int i = start; i <= K-(6-weight); ++i ){
		int tmp = cnt;
		int l = K-i-1;
		int r = 6-weight-1;
		int a = c(l,r);
		if( a == 0 ){
			continue;
		}
		cnt += a;
		for( int j = tmp; j < cnt; ++j ){
			check[j+index][weight] = s[i];
		}
		fill(i+1,weight+1,tmp+index);
	}
	return 0;
}

int main(){
	while(true){
		for( int j = c(K,6)-1; j >= 0; --j ){
			for( int i = 0; i < 6; ++i ){
				check[j][i] = 0;
			}
		}
		scanf("%d",&K);
		max = c(K,6);
		if( K == 0 ){
			return 0;
		}
		for( int i = 0; i < K; ++i ){
			scanf("%d",&s[i]);
		}
		fill(0,0,0);
		for( int i = 0; i < max; ++i ){
			for( int j = 0; j < 6; ++j ){
				printf("%d ",check[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
