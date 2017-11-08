#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
struct pos {
	int y,x;
};
std::queue<pos> q;
int big,n,arr[102][102],small,check[101][101],num[201];
int min( int a, int b ){
	return a<b?a:b;
}
int max( int a, int b ){
	return a>b?a:b;
}
int abs( int a ){
	return a<0?-a:a;
}
pos d[4] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0 , -1 } };
int bfs(){
	pos now = q.front();
	int y = now.y;
	int x = now.x;
	for( int i = 0; i < 4; ++i ){
		int dy = now.y+d[i].y;
		int dx = now.x+d[i].x;
		if( check[dy][dx] == 0 && small <= arr[dy][dx] && arr[dy][dx] <= big ){
			check[dy][dx] = 1;
			pos next = { dy, dx };
			q.push(next);
		}
	}
	return 0;
}

void clear(){
	for( int i = 1; i <= n; ++i ){
		for( int j = 1; j <= n; ++j ){
			check[i][j] = 0;
		}
	}
	while( q.size() > 0 ){
		q.pop();
	}
}


int main(){
	scanf("%d",&n);
	int result = 500;
	for( int i = 0; i <= n+1; ++i ){
		for( int j = 0; j <= n+1; ++j ){
			arr[i][j] = 500;
		}
	}
	std::vector<int> v;
	for( int i = 1; i <= n; ++i ){
		for( int j = 1; j <= n; ++j ){
			scanf("%d",&arr[i][j]);
			if( num[ arr[i][j] ] == 0 ){
				num[ arr[i][j] ] = 1;
				v.push_back(arr[i][j]);
			}
		}
	}
	std::sort(v.begin(),v.end());
	for( int i = 0; i < v.size(); ++i ){
		small = v[i];
		int left = 0;
		int right = v.size()-1;
		int flag = 0;
		if( arr[1][1] < small ){
			break;
		}
		while( left <= right ){
			clear();
			int mid = (left+right)/2;
			big = v[mid];
			if( arr[1][1] > big ){
				printf("%d %d\n",small,big);
				left = mid + 1;
				continue;
			}
			pos start = { 1, 1 };
			check[1][1] = 1;
			q.push(start);
			while( check[n][n] == 0 && q.size() > 0 ){
				bfs();
				q.pop();
			}
			if( check[n][n] == 1 ){
				result = min( result, big-small );
				right = mid - 1;
			} else {
				printf("%d %d\n",small,big);
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

