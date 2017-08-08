#include<stdio.h>
int N,a[8];
int check[8];
int b[8];
int abs( int a ){
	return a<0?-a:a;
}
int max( int a, int b ){
	return a>b?a:b;
}
int f(int cnt){
	int ret = 0;
	if( cnt == N ){
		int sum = 0;
		for( int i = 0; i < N-1; ++i ){
			sum += abs(b[i]-b[i+1]);
		}
		return sum;
	}
	for( int i = 0; i < N; ++i ){
		if( check[i] != 1 ){
			b[cnt] = a[i];
			check[i] = 1;
			ret = max( ret, f( cnt+1 ) );
			check[i] = 0;
		}
	}
	return ret;
}

int main(){
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	printf("%d\n",f(0));
	return 0;
}
