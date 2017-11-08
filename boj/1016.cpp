#include<stdio.h>
unsigned long long int i,j,k;
unsigned long long int cnt = 0;
unsigned long long int min, max, tmp, r;
int arr[2000000] = {0,};
int main(){
	scanf("%lld %lld",&min,&max);
	for( i = 2; i*i <= max; ++i ){
		tmp = i*i;
		r = min%tmp;
		if( r == 0 ){
			k = 0;
		} else {
			k = -r+tmp;
		}
		for( ; k <= max-min; k+=tmp ){
			if( arr[k] == 0 ){
				arr[k] = 1;
				cnt++;
			}
		}
	}
	printf("%lld",(max-min+1)-cnt);
	return 0;
}
