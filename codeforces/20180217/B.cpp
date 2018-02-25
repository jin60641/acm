#include<stdio.h>
int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int cnt, l = 1, r = 1000000, lmax = 0, rmax = 0;
	scanf("%d",&cnt);
	for( int i = 0; i < cnt; ++i ){
		int a;
		scanf("%d",&a);
		if( a <= 500000 ){
			lmax = a-1;
		} else {
			rmax = max(rmax,1000000-a);
		}
	}
	printf("%d\n",max(lmax,rmax));
	return 0;
}
