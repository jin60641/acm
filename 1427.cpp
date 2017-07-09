#include<stdio.h>
#include<algorithm>

using namespace std;

int cmp( int a, int b ){
	return a>b;
}

int main(){
	char s[12];
	int a[10];
	scanf("%s",&s);
	int i;
	for( i = 0; s[i] != '\0'; ++i ){
		a[i] = s[i]-48;
	}
	sort(a,a+i,cmp);
	for( int j = 0; j < i; ++j ){
		printf("%d",a[j]);
	}
}
