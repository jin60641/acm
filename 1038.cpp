#include<stdio.h>
int N, a[11], size = 1;
void add(int i){
	if( i != size - 1 && a[i] + 1 >= a[i+1] ){
		a[i] = i;
		add(i+1);
	} else {
		++a[i];
		if( a[i] == 10 ){
			a[i] = i;
			if( i == size - 1){
				a[size++] = i+1;
			} else {
				add(i+1);
			}
		}
	}
} 
int main(){
	scanf("%d",&N);
	while( N-- && size <= 10 ){
		add(0);
	}
	if( size >= 11 ){
		printf("-1");
	} else {
		for( int i = size-1; i >= 0; --i ){
			printf("%d",a[i]);
		}
	}
	printf("\n");
	return 0;
}
