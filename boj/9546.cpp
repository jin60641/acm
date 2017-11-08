#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int N;
		int a = 1;
		scanf("%d",&N);
		while( N-- ){
			a*=2;
		}
		printf("%d\n",a-1);
	}
	return 0;
}
