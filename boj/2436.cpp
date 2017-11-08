#include<stdio.h>
#include<math.h>

long long int gcd( long long int a, long long int b ){
	if( a < b ){
		long long int tmp = b;
		b = a;
		a = tmp;
	}
	long long int r;
	do {
		r = a%b;
		a = b;
		b = r;
	} while( r != 0 );
	return a;
}

int main(){
	long long int a, b, c;
	scanf("%lld %lld",&a,&b);
	for( long long int i = (long long int)(sqrt((float)a) * sqrt((float)b)); i >= 1; --i ){
		if( (a*b)%i == 0 && a == gcd(i,(a*b)/i) ){
			printf("%lld %lld\n", i,(a*b)/i);
			break;
		}
	}
	return 0;
}
