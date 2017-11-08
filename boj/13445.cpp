#include<stdio.h>

int x(int a, int b){
	return (a|b) - (a&b);
}

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	int a[100000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a);
	}
	printf("%d",x(13,5));
	return 0;
}
