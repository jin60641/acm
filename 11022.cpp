#include<stdio.h>

int main(){
	int i = 0;
	int T;
	scanf("%d",&T);
	while( ++i <= T ){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d + %d = %d\n",i,a,b,a+b);
	}
	return 0;
}
