#include<stdio.h>

int main(){
	int tot = 0;
	int tmp = 0;
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		if( a == 1 ){
			++tmp;
			tot += tmp;
		} else {
			tmp = 0;
		}
	}
	printf("%d\n",tot);
}
