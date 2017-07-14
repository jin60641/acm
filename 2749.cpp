#include<stdio.h>

int main(){
	long long int a = 0;
	long long int b = 1;
	long long int n;
	scanf("%lld",&n);
	while( --n ){
		long long int tmp = b%1000000;
		b += a%1000000;
		a = tmp%1000000;
	}
	printf("%lld\n",b%1000000);
	return 0;
}
