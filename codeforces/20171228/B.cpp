#include<stdio.h>

int max( int a, int b ){
	return a>b?a:b;
}
int min( int a, int b ){
	return a<b?a:b;
}

int main(){
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	int result = 0;
	for( int i = 1; i <= a; ++i ){
		for( int j = 1; j <= b; ++j ){
			int ad = a%i?a/i+1:a/i;
			int bd = b%j?b/j+1:b/j;
			if( ad+bd != n ){
				continue;
			}
			int tmp = 200000;
			if( a%i != 0 ){
				tmp = min(tmp,a%i);
			} else {
				tmp = min(tmp,i);
			}
			if( b%j != 0 ){
				tmp = min(tmp,b%j);
			} else {
				tmp = min(tmp,j);
			}
			//printf("i : %d / j : %d / ad : %d / bd : %d / tmp : %d\n",i,j,ad,bd,tmp);
			result = max( result, tmp );
		}
	}
	printf("%d\n",result);
	return 0;
}
