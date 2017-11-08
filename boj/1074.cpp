#include<stdio.h>

int main(){
	int N,r,c;
	scanf("%d %d %d",&N,&r,&c);
	int left,right,top,bottom,size;
	left = 0;
	top = 0;
	right = 1;
	for( int i = 0; i < N; ++i ){
		right*=2;
	}
	size = right;
	right--;
	bottom = right;
	int num = 0;
	while( size>=1 ){
		size/=2;
		if( r >= size+top && c >= size+left ){
			top += size;
			left += size;
			num += size*size*3;
		} else if( r >= size+top && c < size+left ){
			top += size;
			num += size*size*2;
		} else if( r < size+top && c >= size+left ){
			left += size;
			num += size*size;
		} else if( r < size+top && c < size+left ){
		}
	}
	printf("%d\n",num);
	
	return 0;
}
