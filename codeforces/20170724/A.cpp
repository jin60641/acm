#include<stdio.h>

int main(){
	long long int n, k;
	scanf("%lld %lld",&n,&k);
	long long int a = n - n%k;
	if( n < k ){
		printf("NO\n");
	} else if( n == k ){
		printf("YES\n");
	} else if( n%k == 0 && (a/k)%2 == 1 ){
		printf("YES\n");
	} else if( n%k == 0 && (a/k)%2 == 0 ){
		printf("NO\n");
	} else if( (a/k)%2 == 1 ){
		printf("YES\n");
	} else if( (a/k)%2 == 0 ){
		printf("NO\n");
	}
	return 0;
}
