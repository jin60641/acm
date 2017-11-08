#include<stdio.h>

int zero = 0;
int plus = 0;

int f(int n){
	if(n==0){
		zero++;
		return 0;
	} else if( n == 1 ){
		plus++;
		return 0;
	} else {
		return f(n-1) + f(n-2);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		zero = 0;
		plus = 0;
		int N;
		scanf("%d",&N);
		f(N);
		printf("%d %d\n",zero,plus);
	}
}
