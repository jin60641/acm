#include<stdio.h>

int main(){
	for( int i = 0; i < 3; ++i ){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int tot = a+b+c+d;
		char r;
		switch(tot){
			case 4: r = 'E';
				break;
			case 0: r = 'D';
				break;
			case 3: r = 'A';
				break;
			case 1: r = 'C';
				break;
			case 2: r = 'B';
				break;
		}
		printf("%c\n",r);
	}
}
