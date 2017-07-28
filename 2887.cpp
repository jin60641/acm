#include<stdio.h>


struct pos {
	int x,y,z;
}

int abs(int a){
	return a>=0?a:-a;
}

int min(pos a, pos b){
	int x = abs(a.x-b.x);
	int y = abs(a.y-b.y);
	int z = abs(a.z-b.z);
	if( x >= y && x >= z ){
		return x;
	} else if( y >= x && y >= z ){
		return y;
	} else if( z >= x && z >= y ){
		return z;
	}
}

pos a[100000];

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		pos p;
		scanf("%d %d %d",&p.x,&p.y,&p.z);
		for( int j = 0; j < N; ++j ){
			
		}
	}
	return 0;
}
