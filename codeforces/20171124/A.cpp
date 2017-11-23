#include<stdio.h>

int main(){
	int N, s = 3;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int win;
		scanf("%d",&win);
		if( win == s ){
			printf("NO\n");
			return 0;
		}
		if( win == 1 ){
			if( s == 2 ){
				s = 3;
			} else {
				s = 2;
			}
		} else if( win == 2 ){
			if( s == 1 ){
				s = 3;
			} else {
				s = 1;
			}
		} else if( win == 3 ){
			if( s == 1 ){
				s = 2;
			} else {
				s = 1;
			}
		}
	}
	printf("YES\n");
}
