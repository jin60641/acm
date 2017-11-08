#include<stdio.h>

int a[100];
int result[10000];
int N;
int K;

int f(int k){
	if( k == 0 ){
		return 0;
	}
	if( result[k-1] != 0 ){
		return result[k-1];
	}
	int m = 100000;
	for( int i = 0; i < N; ++i ){
		if( k >= a[i] ){
			int n = f(k-a[i])+1;
			if( n < m ) {
				m = n;
			}
		}
	}
	result[k-1] = m;
	return m;
}

int main(){
	scanf("%d %d",&N,&K);
	for( int i = 0; i < N; ++ i ){
		scanf("%d",&a[i]);
	}
	int r = f(K);
	if( r == 100000 ){
		printf("-1");
	} else {
		printf("%d\n",r);
	}
	return 0;
}

