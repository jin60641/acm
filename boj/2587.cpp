#include<stdio.h>
#include<algorithm>

int main(){
	int a[5];
	int tot = 0;
	for( int i = 0; i < 5; ++i ){
		scanf("%d",&a[i]);
		tot += a[i];
	}
	std::sort(a,a+5);
	printf("%d\n%d",tot/5,a[2]);
	return 0;
}
