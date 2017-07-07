#include<stdio.h>

int result[10000001];
int F,S,G,U,D;
int f(int s, int cnt){
	if( s > F || s < 1 ){
	} else if( result[s] > cnt ){
		result[s] = cnt;
		f(s+U,cnt+1);
		f(s-D,cnt+1);
	}
	return 0;
}
int main(){
	scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
	for( int i = 1; i <= F; ++i ){
		result[i] = 10000000;
	}
	f(S,0);
	if( result[G] == 10000000 ){
		printf("use the stairs\n");
	} else {
		printf("%d\n",result[G]);
	}
	return 0;
}
