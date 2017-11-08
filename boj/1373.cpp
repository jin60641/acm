#include<stdio.h>
#include<string.h>
#include<stack>

int main(){
	char s[1000001];
	scanf("%s",s);
	int sum = 0;
	int multi = 1;
	std::stack<int> r;
	
	for( int i = strlen(s)-1; i >= 0; --i ){
		sum += (s[i]-'0')*multi;
		multi*=2;
		if( multi == 8 || i == 0){
			multi = 1;
			r.push(sum);
			sum = 0;
		}
	}
	while( r.size() > 0 ){
		printf("%d",r.top());
		r.pop();
	}
	return 0;
}
