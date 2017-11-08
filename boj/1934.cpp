#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d %d",&a,&b);
		int mod = a%b;
		int A,B;
		A = a;
		B = b;
		while( a%b ){
			a = b;
			b = mod;
			mod = a%b;
		}
		printf("%d\n",(A*B)/b);
	}
}
