#include<stdio.h>

int main(){
	int A,B,V;
	scanf("%d %d %d",&A,&B,&V);
	if( (V-A)%(A-B) ){
		printf("%d",(V-A)/(A-B)+2);
	} else {
		printf("%d",(V-A)/(A-B)+1);
	}
}
