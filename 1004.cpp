#include<stdio.h>

int pow( int a ){
	return a*a;
}

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int n;
		scanf("%d",&n);
		int cnt = 0;
		for( int i = 0; i < n; ++i ){
			int cx, cy, r;
			scanf("%d %d %d",&cx,&cy,&r);
			int d1 = pow(x1 - cx) + pow(y1 - cy );
			int d2 = pow(x2 - cx) + pow(y2 - cy );
			r = pow(r);
			if( ( d1 < r && d2 > r ) || ( d2 < r && d1 > r ) ){
				++cnt;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
