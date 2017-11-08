#include<stdio.h>

int check[42];
int main(){
	int cnt = 0;
	for( int i = 0; i < 10; ++i ){
		int a;
		scanf("%d",&a);
		if( check[a%42] == 0 ){
			check[a%42] = 1;
			++cnt;	
		}
	}
	printf("%d\n",cnt);
	return 0;
}
