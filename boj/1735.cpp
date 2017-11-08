#include<stdio.h>

int f(int a,int b){
	while(true){
		int r = a%b;
		if( r == 0 ){
			return b;
		} 
		a = b;
		b = r;
	}
	return 0;
}

int main(){
	int a,b,c,d;
	scanf("%d %d",&a,&b);
	scanf("%d %d",&c,&d);

	int ab = f(a,b);
	a /= ab;
	b /= ab;
	int cd = f(c,d);
	c /= cd;
	d /= cd;

	int r = b*d/f(b,d);
	a *= r/b;
	c *= r/d;

	int s = a+c;
	int sr = f(s,r);
	s /= sr;
	r /= sr;
	
	printf("%d %d",s,r);
}
