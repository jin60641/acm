#include<stdio.h>
#include<stack>

int f(int a){
	std::stack<int> s;
	while( a != 0 ){
		s.push(a%10);
		a/=10;
	}
	int multi = 1;
	int ret = 0;
	while( s.size() > 0 ){
		ret += s.top()*multi;
		multi *= 10;
		s.pop();
	}
	return ret;
}
int main(){
	int X, Y;
	scanf("%d %d",&X,&Y);
	printf("%d\n",f(f(X)+f(Y)));
	return 0;
}
