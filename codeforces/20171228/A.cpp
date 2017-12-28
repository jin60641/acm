#include<stdio.h>
#include<algorithm>

struct pair {
	int index, value;
};

bool cmp(pair a, pair b){
	if( a.value == b.value ){
		return a.index < b.index;
	}
	return a.value < b.value;
}

int main(){
	int N;
	scanf("%d",&N);
	pair a[100000];
	for( int i = 0; i < N; ++i ){
		a[i].index = i;
		scanf("%d",&a[i].value);
	}
	std::sort(a,a+N,cmp);
	int min = a[0].value;
	int result = 200000;
	for( int i = 1; i < N; ++i ){
		if( a[i].value != min ){
			break;
		}
		int d =  a[i].index - a[i-1].index;
		if( d < result ){
			result = d;
		}
	}
	printf("%d\n",result);
	return 0;
}
