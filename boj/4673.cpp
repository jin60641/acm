#include<stdio.h>

int check[10000];

int main(){
	for( int i = 1; i <= 10000; ++i ){
		int sum = i;
		int tmp = i;
		while( tmp != 0 ){
			sum += tmp%10;
			tmp/=10;
		}
		if( sum < 10000 ){
			check[sum] = 1;
		}
		if( check[i] == 0 ){
			printf("%d\n",i);
		}
	}
	return 0;
}
