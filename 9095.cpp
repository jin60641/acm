#include<stdio.h>

int f(int a){
	int ret = 1;
	int tmp = a;
	while(tmp > 0){
		ret *= tmp;
		tmp--;
	}
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int cnt = 0;
		int a = n/3;
		while( a >= 0 ){
			int tmp = n - a*3;
			int b = tmp/2;
			while( b >= 0 ){
				int tmp2 = tmp - b*2;
				cnt += f(a+b+tmp2)/(f(a)*f(b)*f(tmp2));
				--b;
			}
			--a;
		}
		printf("%d\n",cnt);
	}
	return 0;
}

