#include<stdio.h>

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int N;
	int result = 0;
	scanf("%d",&N);
	while( N-- ){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if( a == b && b == c ){
			result = max(result,10000+a*1000);
		} else if( a == b ){
			result = max(result,1000+a*100);
		} else if( b == c ){
			result = max(result,1000+b*100);
		} else if( a == c ){
			result = max(result,1000+a*100);
		} else {
			result = max(result, max( a, max(b,c) )*100 );
		}
	}
	printf("%d\n",result);
}
