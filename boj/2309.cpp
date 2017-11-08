#include<stdio.h>
#include<algorithm>

const int num = 9;
int main(){
	int a[num];
	int tot = 0;
	for( int i = 0; i < num; ++i ){
		scanf("%d", &a[i] );
		tot += a[i];
	}
	std::sort(a,a+num);
	for( int i = 0; i < num-1; ++i ){
		for( int j = i+1; j < num; ++j ){
			if( tot - a[i] - a[j] == 100 ){
				for( int k = 0; k < num; ++k ){
					if( k == i || k == j ){
						continue;
					}
					printf("%d\n",a[k]);
				}
				return 0;
			}
		}
	}
	return 0;
}
