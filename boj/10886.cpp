#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int sum = 0;
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		a==0?--sum:++sum;
	}
	printf("Junhee is%s cute!\n",sum>0?"":" not");
	return 0;
}
