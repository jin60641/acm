#include<stdio.h>
#include<vector>

struct pos {
	int x;
	int y;
};
std::vector<struct pos> q;

int check[52][52];
int a[52][52];
int max = 0;
int w,h;

int push( int x, int y ){
	struct pos p = { x, y };
	q.push_back(p);
}

int clear(){
	for( int i = 0; i < h; ++i ){
		for( int j = 0; j < w; ++j ){
			check[i][j] = -1;
		}
	}
	q.clear();
}

int bfs(int start){
	if( q.size() <= start ){
		return 0;
	}
	int x = q[start].x;
	int y = q[start].y;
	if( check[y][x] > max ){
		max = check[y][x];
	}
	
	if( x >= 1 && a[y][x-1] == 1 && ( check[y][x-1] == -1 || check[y][x-1] > check[y][x] + 1 ) ){
		check[y][x-1] = check[y][x] + 1;
		push(x-1,y);
	}
	if( x < w-1 && a[y][x+1] == 1 && ( check[y][x+1] == -1 || check[y][x+1] > check[y][x] + 1 ) ){
		check[y][x+1] = check[y][x] + 1;
		push(x+1,y);
	}
	if( y >= 1 && a[y-1][x] == 1 &&( check[y-1][x] == -1 || check[y-1][x] > check[y][x] + 1 ) ){
		check[y-1][x] = check[y][x] + 1;
		push(x,y-1);
	}
	if( y < h-1 && a[y+1][x] == 1 && ( check[y+1][x] == -1 || check[y+1][x] > check[y][x] + 1 ) ){
		check[y+1][x] = check[y][x] + 1;
		push(x,y+1);
	}
	
	bfs(start+1);
	return 0;
}


int main(){
	scanf("%d %d",&h,&w);
	for( int i = 0; i < h; ++i ){
		char s[51];
		scanf("%s",s);
		for( int j = 0; j < w; ++j ){
			a[i][j] = (s[j]=='W')?0:1;
		}
	}
	clear();
	for( int i = 0; i < h; ++i ){
		for( int j = 0; j < w; ++j ){
			if( a[i][j] == 1 ){
				push(j,i);
				check[i][j] = 0;
				bfs(0);
				clear();
			}
		}
	}
	printf("%d\n",max);
}
