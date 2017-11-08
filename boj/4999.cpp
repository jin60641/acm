#include<stdio.h>

int main(){
	char s1[1010];
	char s2[1010];
	scanf("%s",s1);
	scanf("%s",s2);
	int a,b;
	for( a = 0; s1[a] != 'h'; ++a );
	for( b = 0; s2[b] != 'h'; ++b );
	if( a >= b ){
		printf("go\n");
	} else {
		printf("no\n");
	}
	return 0;
}
