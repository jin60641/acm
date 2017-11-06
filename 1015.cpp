#include<stdio.h>
#include<algorithm>
struct pair{
	int a,value;
};
bool cmp( pair a, pair b ){
	if( a.value == b.value ){
		return a.a < b.a;
	} else {
		return a.value < b.value;
	}
}
int main(){
	int N,p[50];
	scanf("%d",&N);
	pair a[50];
	for( int i = 0; i < N; ++i ){
		a[i].a = i;
		scanf("%d",&a[i].value);
	}
	std::sort(a,a+N,cmp);
	for( int i = 0; i < N; ++i ){
		p[a[i].a] = i;
	}
	for( int i = 0; i < N; ++i ){
		printf("%d ",p[i]);
	}
	printf("\n");
	return 0;
}
