#include<stdio.h>
int check[101];

int main(){
	int tot = 0;
	int max = 0;
	for( int i = 0; i < 10; ++i ){
		int a;
		scanf("%d",&a);
		a/=10;
		++check[a];
		if( check[a] > check[max] ){
			max = a;
		}
		tot += a;
	}
	printf("%d\n%d\n",tot,max*10);
	return 0;
}
