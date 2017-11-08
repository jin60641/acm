#include<stdio.h>

int main(){
	int A,B;
	int arr[1000];
	scanf("%d %d",&A,&B);
	A--;
	B--;
	int cnt = 1;
	int num = 1;
	for( int i = 0; i < 1000; ++i ){
		arr[i] = num;
		--cnt;
		if( cnt == 0 ){
			++num;
			cnt = num;
		}
	}
	for( int i = 1; i < 1000; ++i ){
		arr[i] += arr[i-1];
	}
	printf("%d",arr[B]-((A==0)?0:arr[A-1]) );
}
