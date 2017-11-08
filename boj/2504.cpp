#include<stdio.h>

char s[31];
const int SMALL = 2;
const int BIG = 3;
int skip = 0;
int flag = 0;

struct obj {
	int tot;
	int skip;
};

struct obj f(int start,int type){
	struct obj o = { 0, 0 };
	struct obj tmp;
	for( int i = start; s[i+1] != '\0'; ++i ){
		if( s[i+1] == '(' || s[i+1] == '[' ){
			if( s[i+1] == '(' ){
				tmp = f(i+1,SMALL);
			} else {
				tmp = f(i+1,BIG);
			}
			o.tot += tmp.tot;
			i += tmp.skip;
		} else {
			if( o.tot == 0 ){
				o.tot = 1;
			}
			o.skip = i-start+1;
			if( s[i+1] == ')' && type == SMALL){
				o.tot *= SMALL;
			} else if( s[i+1] == ']' && type == BIG ){
				o.tot *= BIG;
			} else {
				flag = 1;
			}
			return o;
		}
	}
	return o;
}

int main(){
	scanf("%s",s);	
	int tot = 0;
	int small = 0;
	int big = 0;
	for( int i = 0; s[i] != '\0'; ++i ){
		switch( s[i] ){
			case '(':
				++small;
				break;
			case '[':
				++big;
				break;
			case ')':
				--small;
				break;
			case ']':
				--big;
				break;
		}
		if( small < 0 || big < 0 ){
			printf("0\n");
			return 0;
		}
	}
	if( small != 0 || big != 0 ){
		printf("0\n");
		return 0;
	}
	
	for( int i = 0; s[i] != '\0'; ++i ){
		struct obj o;
		if( s[i] == '(' ){
			o = f(i,SMALL);
		} else if( s[i] == '[' ){
			o = f(i,BIG);
		}
		tot += o.tot;
		i += o.skip;
	}
	if( flag == 1 ){
		printf("0\n");
	} else {
		printf("%d\n",tot);
	}
}
