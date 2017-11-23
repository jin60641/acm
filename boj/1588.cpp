#include<stdio.h>
int tmp[3];
int result[3];
int a,l,r,N;
int arr[3][2][3] = { { { 1, 3, 2 }, { 1, 1, 1 } }, { { 2, 1, 1 }, { 2, 1, 0 } }, { { 2, 3, 2 }, { 0, 2, 1 } } };
void f(int a, int remain, int index ){
	if( remain == 0 ){
		if( l <= index && index <= r ){
			++result[a-1];
		}
	} else {
		for( int i = 0; i < 3; ++i ){
			f( arr[a-1][0][i], remain-1, index*3+i, tmp );
		}
	}
}
int main(){
	scanf("%d %d %d %d",&a,&l,&r,&N);
	++tmp[a-1];
	f(a,N,0,{0,0,0});
	printf("\n");
}
