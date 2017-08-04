#include<stdio.h>
#include<string.h>
#include<stack>

int main(){
	char o[333335];
	std::stack<int> s;
	scanf("%s",o);
	int n = strlen(o);
	if( n == 1 && o[0] == '0' ){
		printf("0\n");
		return 0;
	}
	for( int i = n-1; i >= 0; --i ){
		int a = o[i] - '0';
		for( int j = 0; j < 3; ++j ){
			s.push(a%2);
			a/=2;
		}
	}
	int flag = 0;
	while( s.size() > 0 ){
		if( flag == 0 && s.top() == 0 ){
		} else {
			flag = 1;
			printf("%d",s.top());
		}
		s.pop();
	}
	printf("\n");
	return 0;
}
