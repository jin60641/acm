#include<stdio.h>

int G, P, check[100001], cnt = 0, g[100001];
int find(int a){
	if( check[a] == a ){
		return a;
	}
	check[a] = find(check[a]);
	return check[a];
}

int main(){
	scanf("%d %d",&G,&P);
	for( int i = 1; i <= G; ++i ){
		check[i] = i;
	}
	for( int i = 1; i <= P; ++i ){
		scanf("%d",&g[i]);
	}
	for( int i = 1; i <= P; ++i ){
		int r = find(g[i]);
		if( r ){
			++cnt;
			check[r] = find(r-1);
		} else {
			break;
		}
	}
	printf("%d\n",cnt);
}
