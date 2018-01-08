#include<stdio.h>

int main(){
	int n,m,tmp=1;
	scanf("%d %d",&n,&m);
	for( int i = 0; i < n; ++i ){
		tmp *= 2;
		if( tmp > m ){
			break;
		}
	}
	printf("%d\n",m%tmp);
	return 0;
}
