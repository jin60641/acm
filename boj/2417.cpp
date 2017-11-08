#include<stdio.h>
int main(){
	long long int n;
	scanf("%lld",&n);
	if( n == 2 ){
		printf("2\n");
		return 0;
	} else if( n == 1 ){
		printf("1\n");
		return 0;
	}
	
	long long int l,r,m;
	l = 0;
	r = n-1;
	while(l<=r){
		m = (l+r)/2;
		if( m > 0 && m == n/m && n%m == 0 ){
			r = m-1;
		} else if( m > n/m ){
			r = m-1;
		} else {
			l = m+1;
		}
	}
	printf("%lld\n",l);
	return 0;
}	
