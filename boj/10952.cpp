#include<stdio.h>

int main(){
	while(true){
		int A,B;
		scanf("%d %d",&A,&B);
		if( A+B == 0 ){
			return 0;
		}
		printf("%d\n",A+B);
	}
}
