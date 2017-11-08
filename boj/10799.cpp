#include<stdio.h>
#include<stack>
#include<vector>

struct pair {
	int open;
	int close;
};

std::stack<int> open;
std::vector<pair> v;

int main(){
	char s[100001];
	scanf("%s",s);
	int tot = 0;
	int cnt = 0;
	for( int i = 0; s[i] != 0; ++i ){
		if( s[i] == '(' ){
			++cnt;
			open.push(i);
		} else {
			--cnt;
			int o = open.top();
			if( o+1 == i ){
				tot += cnt;
			} else {
				tot += 1;
			}
			open.pop();
			pair p = { o, i };
			v.push_back(p);
		}
	}
	printf("%d\n",tot);
	return 0;
}
