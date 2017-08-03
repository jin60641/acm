#include<stdio.h>

int main(){
	long long int X;
	long long int Y;
	while( scanf("%lld %lld",&X,&Y) != EOF ){
		long long int Z = Y*100/X;
		long long int left = 1;
		long long int right = 2000000010;
		while( left <= right ){
			long long int mid = (left+right)/2;
			if( (Y+mid)*100/(X+mid) == Z ){
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		if( (Y+left)*100/(X+left) == Z ){
			printf("-1\n");
		} else {
			printf("%lld\n",left);
		}
	}
	return 0;
}
