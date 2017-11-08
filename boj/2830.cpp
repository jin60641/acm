#include<stdio.h>

int names[1000010];
int bins[1000010][21];

int sum(int a,int b){
	int index = 0;
	int add = 1;
	int tot = 0;
	while( !( add > names[a] && add > names[b] ) ){
		if( bins[a][index] != bins[b][index] ){
			tot += add;
		}
		add *= 2;
		index++;
	}
	return tot;
}

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int name;
		scanf("%d",&name);
		names[i] = name;
		int index = 0;
		while( name > 0 ){
			bins[i][index] = name%2;
			name /= 2;
			index++;
		}
	}
	long long int tot = 0;	
	for( int i = 0; i < N; ++i ){
		for( int j = i+1; j < N; ++j ){
			tot += sum(i,j);
		}
	}
	printf("%lld",tot);
}
