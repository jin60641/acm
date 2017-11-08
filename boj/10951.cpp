#include<stdio.h>

int main(){
	while(true){
		int A,B;
		if( scanf("%d",&A) == EOF ){
			return 0;
		}
		if( scanf("%d",&B) == EOF ){
			return 0;
		}
		printf("%d\n",A+B);
	}
}
