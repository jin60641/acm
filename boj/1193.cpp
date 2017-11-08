#include<stdio.h>

int main(){
	int a = 1;
	int b = 1;
	int X;
	int flag = 1;
	scanf("%d",&X);
	while(--X){
		if( flag == 1 && a - 1 == 0 ){
			++b;
			flag = -1;
		} else if( flag == -1 && b - 1 == 0 ){
			++a;
			flag = 1;
		} else {
			a -= flag;
			b += flag;
		}
	}
	printf("%d/%d\n",a,b);
	return 0;
}
