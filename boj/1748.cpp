#include<stdio.h>

int numlen(int a){
	int len = 0;
	while(a!=0){
		a /= 10;
		++len;
	}
	return len;
}

int main(){
	int N;
	long long int cnt = 10;
	scanf("%d",&N);
	long long int tot = 9;
	int len = numlen(N);
	if( N < 10 ){
		printf("%d\n",N);
		return 0;
	}
	for( int i = 2; i < len; ++i ){
		tot += (cnt*10-cnt)*i;
		cnt*=10;
	}
	tot += (N-cnt+1)*len;
	printf("%lld\n",tot);	
	return 0;
}
