#include<stdio.h>
#include<queue>
#include<stack>

int N;
int max = 0;
const int ODD = 0;
const int EVEN = 1;
struct pos {
	int y,x;
};
pos tile[300000];
int a[500][1000];
int check[300000];
int nums[500][1000];

std::queue<int> q;

int bfs(){
	int num = q.front();
	if( num == 1 && check[num] != -1 ){
		q.pop();
		return 0;
	}
	max = max<num?num:max;

	int x = tile[num].x;
	int y = tile[num].y;
	int flag = y%2;
	if( x >= 2+flag && a[y][x] == a[y][x-1] && check[num-1] == 0 ){
		check[num-1] = num;
		q.push(num-1);
	}
	if( x < N*2-2-flag && a[y][x+1] == a[y][x+2] && check[num+1] == 0 ){
		check[num+1] = num;
		q.push(num+1);
	}
	if( y >= 1 ){
		if( a[y-1][x] == a[y][x] && check[nums[y-1][x]] == 0 ){
			check[nums[y-1][x]] = num;
			q.push(nums[y-1][x]);
		}
		if( a[y-1][x+1] == a[y][x+1] && check[nums[y-1][x+1]] == 0 ){
			check[nums[y-1][x+1]] = num;
			q.push(nums[y-1][x+1]);
		}
	}
	if( y < N-1 ){
		if( a[y+1][x] == a[y][x] && check[nums[y+1][x]] == 0 ){
			check[nums[y+1][x]] = num;
			q.push(nums[y+1][x]);
		}
		if( a[y+1][x+1] == a[y][x+1] && check[nums[y+1][x+1]] == 0 ){
			check[nums[y+1][x+1]] = num;
			q.push(nums[y+1][x+1]);
		}
	}
	q.pop();
	return 0;
}

int main(){
	scanf("%d",&N);
	int start = 1;
	int end = N*N-N/2;
	int flag = ODD;
	int y = 0;
	int cnt = 0;
	for( int i = start; i <= end; ++i ){
		pos p = { y, cnt*2+flag };
		tile[i] = p;
		nums[y][cnt*2+flag] = i;
		nums[y][cnt*2+1+flag] = i;
		scanf("%d %d",&a[y][cnt*2+flag],&a[y][cnt*2+1+flag]);
		if( ( flag == ODD && (cnt+1)%N == 0 ) || ( flag == EVEN && (cnt+1)%(N-1) == 0 ) ){
			flag = !flag;
			++y;
			cnt = 0;
		} else {
			++cnt;
		}
	}
	check[start] = -1;
	q.push(start);
	while( q.size() > 0 ){
		bfs();
	}
	std::stack<int> result;
	int len = 0;
	int now = max;
	while( now != -1 ){
		++len;
		result.push(now);
		now = check[now];
	}
	printf("%d\n",len);
	while( result.size() > 0 ){
		printf("%d ",result.top());
		result.pop();
	}
	return 0;
}
