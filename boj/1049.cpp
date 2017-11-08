#include<stdio.h>
int min( int a, int b ){
	return a<b?a:b;
}
int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	int set_min = 10000;
	int each_min = 10000;
	for( int i = 0; i < M; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		set_min = min( set_min, a );
		each_min = min( each_min, b );
	}
	int arr_min[7] = { 0, };
	for( int i = 1; i <= 6; ++i ){
		arr_min[i] = min( set_min, each_min*i );
	}
	printf("%d\n",arr_min[6]*(N/6)+arr_min[N%6]);
	return 0;
}
