#include<stdio.h>

int f(int n, int from, int by, int to){
	if( n == 1 ){
		printf("%d %d\n", from, to);
	} else {
		f(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		f(n - 1, by, from, to);
	}
	return 0;
}

int main(){
	int n;
	scanf("%d",&n);
	int a = 1;
	for( int i = 0; i < n; ++ i ){
		a *= 2;
	}
	printf("%d\n",a-1);
	f(n,1,2,3);
	return 0;
}

