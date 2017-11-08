#include<stdio.h>

int main(){
	long long int N;
	long long int a = 1;
	scanf("%lld",&N);
	while( N >= 2 ){
		a *= N;
		--N;
	}
	printf("%lld",a);
}
