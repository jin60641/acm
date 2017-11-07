#include<stdio.h>
int cnt[3];
int a,l,r,N;
int arr[3][3] = { { 1, 3, 2 }, { 2, 1, 1 }, { 2, 3, 2 } };
void f(int a, int remain, int index ){
	if( remain == 0 ){
		if( l <= index && index <= r ){
			++cnt[a-1];
		}
	} else {
		for( int i = 0; i < 3; ++i ){
			f( arr[a-1][i], remain-1, index*3+i );
		}
	}
}
int main(){
	scanf("%d %d %d %d",&a,&l,&r,&N);
	f(a,N,0);
	for( int i = 0; i < 3; ++i ) printf("%d ",cnt[i]);
	printf("\n");
}
