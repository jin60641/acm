#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	long long int tot = 0;
	for( int i = 1; i <= N; ++i ){
		tot += i;
	}
	printf("%lld",tot);
}
