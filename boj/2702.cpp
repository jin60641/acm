#include<stdio.h>
int a( int A, int B ){
	if( B == 0){
		return A;
	}
	return a( B, A%B );
}
int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int A,B;
		scanf("%d %d",&A,&B);
		int r = a(A,B);
		printf("%d %d\n",A*B/r,r);
	}
	return 0;
}
