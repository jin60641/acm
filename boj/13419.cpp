#include<stdio.h>
#include<string.h>
#include<queue>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		char s[54];
		scanf("%s",s);
		int len = strlen(s);
		if( len%2 == 1 ){
			for( int i = 0; i < len; ++i ){
				s[i+len] = s[i];
			}
			s[len*2] = '\0';
		}
		std::queue<char> qa;
		std::queue<char> qb;
		for( int i = 0; s[i] != '\0'; ++i ){
			if( i%2 == 0 ){
				qa.push(s[i]);
			} else {
				qb.push(s[i]);
			}
		}
		while( qa.size() > 0 ){
			printf("%c",qa.front());
			qa.pop();
		}
		printf("\n");
		while( qb.size() > 0 ){
			printf("%c",qb.front());
			qb.pop();
		}
		printf("\n");
	}
}
