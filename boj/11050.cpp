#include<stdio.h>

int c(int l, int r){
    if( l < 0 || r < 0 || l < r){
        return 0;
    }
    if( l-r < r ){
        r = l-r;
    }
    double result = 1;
    for( int i = 0; i < r; ++i ){
        result = result*(l-i)/(r-i);
    }
    return (int)(result+1e-9);
}


int main(){
	int l,r;
	scanf("%d %d",&l,&r);
	printf("%d",c(l,r));
	return 0;
}
