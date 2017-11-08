#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

int main(){
	int N;
	int num;
	char str[100];
	scanf("%d",&N);
	stack<int> s;
	for( int i = 0; i < N; ++i ){
		scanf("%s",str);
		if( strcmp("push",str) == 0 ){
			scanf("%d",&num);
			s.push(num);
		} else if( strcmp("top",str) == 0 ){
			if(s.empty()){
				printf("-1\n");
			} else {
				printf("%d\n",s.top());
			}
		} else if( strcmp("size",str) == 0 ){
			printf("%d\n",s.size());
		} else if( strcmp("empty",str) == 0 ){
			if(s.empty()){
				printf("1\n");
			} else {
				printf("0\n");
			}
		} else if( strcmp("pop",str) == 0 ){
			if(s.empty()){
				printf("-1\n");
			} else {
				printf("%d\n",s.top());
				s.pop();
			}
		}
	}
}
