#include<stdio.h>
#include<vector>

struct pos {
	int y,x;
};
int cnt = 0;
	int Y,X;
int year = 0;

std::vector<pos> ice;

int check[300][300];
int a[300][300];


int tmp = 0;
int dfs(int y, int x){
    if( check[y][x] == 1 || a[y][x] <= 0 ){
        return 0;
    }
    check[y][x] = 1;
    ++tmp;
    dfs(y-1,x);
    dfs(y+1,x);
    dfs(y,x-1);
    dfs(y,x+1);
    return 0;
}

int f( int y, int x){
	if( a[y][x] <= 0 ){
		return 0;
	}
	int side = 0;
	if( a[y-1][x] == 0 || ( a[y-1][x] < 0 && -a[y-1][x] < year ) ){
		++side;
	}
	if( a[y+1][x] == 0 || ( a[y+1][x] < 0 && -a[y+1][x] < year ) ){
		++side;
	}
	if( a[y][x-1] == 0 || ( a[y][x-1] < 0 && -a[y][x-1] < year ) ){
		++side;
	}
	if( a[y][x+1] == 0 || ( a[y][x+1] < 0 && -a[y][x+1] < year ) ){
		++side;
	}
	a[y][x] -= side;
	if( a[y][x] <= 0 ){
		a[y][x] = -year;
		--cnt;
	}
}

int clear(){
	tmp = 0;
	for( int i = 0; i < Y; ++i ){
		for( int j = 0; j < X; ++j ){
			check[i][j] = 0;
		}
	}
}

int main(){
	scanf("%d %d",&Y,&X);
	for( int i = 0; i < Y; ++i ){
		for( int j = 0; j < X; ++j ){
			scanf("%d",&a[i][j]);
			if( a[i][j] > 0 ){
				pos p = {i,j};
				++cnt;
				ice.push_back(p);
			}
		}
	}
	while( cnt > 0 ){
		++year;
		for( std::vector<pos>::iterator i = ice.begin(); i != ice.end(); ++i ){
			if( a[i->y][i->x] <= 0 ){
				continue;
			}
			if( check[i->y][i->x] == 0 ){
				dfs(i->y,i->x);
			}
			if( tmp < cnt ){
				printf("%d\n",year-1);
				return 0;
			}
			f(i->y,i->x);
		}
		clear();
	}
	printf("0\n");
	return 0;
}
