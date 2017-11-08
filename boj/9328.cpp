#include<stdio.h>
#include<queue>
#include<stack>

struct pos {
	int y,x;
};
std::queue<pos> q;
pos d[4] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

std::stack<pos> door[26];
int T,h,w,check[102][102],key[26],flag,result;
char arr[102][102];
int bfs(){
	pos now = q.front();
	int y = now.y;
	int x = now.x;
	for( int i = 0; i < 4; ++i ){
		int dy = y + d[i].y;
		int dx = x + d[i].x;
		if( 0 <= dy && dy <= h+1 && 0 <= dx && dx <= w+1 && check[dy][dx] == 0 && arr[dy][dx] != '*' ){
			if( arr[dy][dx] >= 'A' && arr[dy][dx] <= 'Z' && key[ arr[dy][dx] - 'A' ] == 0 ){
				pos d = { dy, dx };
				door[ arr[dy][dx] - 'A' ].push( d );
				continue;
			}
			if( arr[dy][dx] >= 'a' && arr[dy][dx] <= 'z' ){
				flag = 0;
				key[ arr[dy][dx] - 'a' ] = 1;
				while( door[ arr[dy][dx]-'a' ].size() > 0 ){
					q.push(door[ arr[dy][dx]-'a' ].top());
					door[ arr[dy][dx]-'a' ].pop();
				} 
			} else if( arr[dy][dx] == '$' ){
				++result;
			}
			pos next = { dy, dx };
			q.push(next);
			check[dy][dx] = 1;
		}
	}
}

int clear(){
	result = 0;
	for( int i = 0; i <= 101; ++i ){
		for( int j = 0; j <= 101; ++j ){
			arr[i][j] = '.';
			check[i][j] = 0;
		}
	}
	for( int i = 0; i < 26; ++i ){
		key[i] = 0;
		while( door[i].size() > 0 ){
			door[i].pop();
		}
	}
	flag = 0;
}

int main(){
	scanf("%d",&T);
	while( T-- ){
		clear();
		scanf("%d %d",&h,&w);
		for( int i = 1; i <= h; ++i ){
			scanf("%s",&arr[i][1]);
			arr[i][1+w] = '.';
		}
		char keys[27];
		scanf("%s",keys);
		if( keys[0] != '0' ){
			for( int i = 0; keys[i] != '\0'; ++i ){
				key[keys[i]-'a'] = 1;
			}
		}
		pos start = { 0, 0 };
		q.push(start);
		while( flag == 0 ){
			flag = 1;
			while( q.size() > 0 ){
				bfs();
				q.pop();
			}
		}
		printf("%d\n",result);
	}
}
