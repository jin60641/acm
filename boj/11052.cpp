#include<stdio.h>

int N;
int arr[1001];
int result[1001];

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		scanf("%d",&arr[i]);
	}
	for(int i = 1; i <= N; ++i ){
		int r = 0;
		for( int j = 1; j <= i; ++j ){
			r = max(r,result[i-j]+arr[j]);
		}
		result[i] = r;
	}
	printf("%d\n",result[N]);
}
