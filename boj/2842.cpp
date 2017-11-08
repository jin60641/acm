#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
struct pos{
	int y,x;
};
std::queue<pos> q;
char c[52][52];
int cnt,small,big,visit[52][52],arr[52][52],N;
pos d[8] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 1 }, { -1, -1 }, { 1, -1 }, { -1, 1 } };
int min(int a,int b){
	return a<b?a:b;
}
void clear(){
	for( int i = 1; i <= 50; ++i ){
		for( int j = 1; j <= 50; ++j ){
			visit[i][j] = 0;
		}
	}
	cnt = 0;
}
void bfs(){
	pos now = q.front();
	int y = now.y;
	int x = now.x;
	if( c[y][x] == 'K' ){
		++cnt;
	}
	for( int i = 0; i < 8; ++i ){
		int dy = y + d[i].y;
		int dx = x + d[i].x;
		if( dy <= 0 || dx <= 0 || dx > N || dy > N ){
			continue;
		}
		if( visit[dy][dx] == 0 && small <= arr[dy][dx] && arr[dy][dx] <= big ){
			visit[dy][dx] = 1;
			pos next = { dy, dx };
			q.push(next);
		}
	}
}
int main(){
	pos start;
	scanf("%d",&N);
	int tot = 0;
	for( int i = 1; i <= N; ++i ){
		scanf("%s",&c[i][1]);
		for( int j = 1; j <= N; ++j ){
			if( c[i][j] == 'P' ){
				start.y = i;
				start.x = j;
			} else if( c[i][j] == 'K' ){
				++tot;
			}
		}
	}
	int check[1000001];
	std::vector<int> v;
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			scanf("%d",&arr[i][j]);
			if( check[ arr[i][j] ] == 0 ){
				check[ arr[i][j] ] = 1;
				v.push_back(arr[i][j]);
			}
		}
	}
	std::sort(v.begin(),v.end());
	int result = 5000000;
	for( int i = 0; i < v.size(); ++i ){
		small = v[i];
		if( arr[start.y][start.x] < small ){
			break;
		}
		int left = i;
		int right = v.size()-1;
		int flag = 0;
		while( left <= right ){
			clear();
			int mid = (left+right)/2;
			big = v[mid];
			if( arr[start.y][start.x] > big ){
				left = mid+1;
				continue;
			}
			pos p = { start.y, start.x };
			q.push(p);
			visit[start.y][start.x] = 1;
			while( q.size() > 0 ){
				bfs();
				q.pop();
			}
			if( cnt == tot ){
				right = mid - 1;
				result = min( result, big-small );
				flag = 1;
			} else {
				left = mid + 1;
			}
		}
		if( flag == 0 ){
			break;
		}
	}
	printf("%d\n",result);
	return 0;
}
