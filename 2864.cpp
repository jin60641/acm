#include<stdio.h>

int alen;
int blen;
char a[10];
char b[10];

int getA(){
	int num = 0;
	int add = 1;
	for( int i = alen; i >= 0; --i ){
		num += (a[i]-'0') * add;
		add*=10;
	}
	return num;
}
int getB(){
	int num = 0;
	int add = 1;
	for( int i = blen; i >= 0; --i ){
		num += (b[i]-'0') * add;
		add*=10;
	}
	return num;
}

int main(){
	scanf("%s",a);
	scanf("%s",b);
	for( int i = 0; a[i] != 0; ++i ){
		if( a[i] == '6' ){
			a[i] = '5';
		}
		alen = i;
	}
	for( int i = 0; b[i] != 0; ++i ){
		if( b[i] == '6' ){
			b[i] = '5';
		}
		blen = i;
	}
	printf("%d ",getA()+getB());
	for( int i = 0; a[i] != 0; ++i ){
		if( a[i] == '5' ){
			a[i] = '6';
		}
	}
	for( int i = 0; b[i] != 0; ++i ){
		if( b[i] == '5' ){
			b[i] = '6';
		}
	}
	printf("%d\n",getA()+getB());
	return 0;
}
