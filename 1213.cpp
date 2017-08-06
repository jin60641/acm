#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>

struct pair{
	char c;
	int cnt;
};
std::queue<pair> q;
std::stack<pair> s;
const int alphabet = 'Z'-'A';
int cnt[30];
int main(){
	char str[51];
	scanf("%s",str);
	int len = strlen(str);
	for( int i = 0; i < len; ++i ){
		++cnt[str[i]-'A'];
	}
	pair m = { '\0', 0 };
	for( int i = 0; i <= alphabet; ++i ){
		if( cnt[i]%2 == 1 ){
			if( len%2 == 0 || m.c != '\0' ){
				printf("I'm Sorry Hansoo\n");
				return 0;
			} else {
				m.cnt = cnt[i];
				m.c = i+'A';
			}
		} else if( cnt[i] != 0 ){
			pair p = { 'A'+i, cnt[i]/2 };
			q.push(p);
			s.push(p);
		}
	}
	int flag = 0;
	while( q.size() > 0 ){
		if( m.c != '\0' && flag == 0 && m.c < q.front().c ){
			flag = 1;
			for( int i = 0; i < m.cnt/2; ++i ){
				printf("%c",m.c);
			}
		}
		while( q.front().cnt-- != 0 ){
			printf("%c",q.front().c);
		}
		q.pop();
	}
	if( m.c != '\0' && flag == 0 ){
		flag = 1;
		for( int i = 0; i < m.cnt; ++i ){
			printf("%c",m.c);
		}
	} else if( m.c != '\0' ){
		flag = 0;
		printf("%c",m.c);
	}
	while( s.size() > 0 ){
		if( m.c != '\0' && flag == 0 && m.c > s.top().c ){
			flag = 1;
			for( int i = 0; i < m.cnt/2; ++i ){
				printf("%c",m.c);
			}
		}
		while( s.top().cnt-- != 0 ){
			printf("%c",s.top().c);
		}
		s.pop();
	}
	if( m.c != '\0' && flag == 0 ){
		for( int i = 0; i < m.cnt/2; ++i ){
			printf("%c",m.c);
		}
	}
	printf("\n");
	return 0;
}
