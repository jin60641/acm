#include<stdio.h>

int c(int l, int r){
	if( l-r < r ){
		r = l-r;
	}
	double result = 1;
	for( int i = 0; i < r; ++i ){
		result = result*(l-i)/(r-i);
	}
	return (int)result;
}

int main(){
	int k;
	while(true){
		scanf("%d",&k);
		if( k == 0 ){
			return 0;
		}
		int s[12];
		int check[2000][6];
		for( int i = 0; i < k; ++i ){
			scanf("%d",&s[i]);
		}
		for( int i = 0; i <= k-6; ++i ){
			printf("%d\n",c(k-i-1,5));
		}
	}
	return 0;
}
