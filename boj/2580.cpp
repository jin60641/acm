#include<stdio.h>
#include<vector>
struct pos {
	int y,x;
};
std::vector<pos> z;
int check[81][9][9];
int find( int cnt ){
	int zx = z[cnt].x;
	int zy = z[cnt].y;
	if( cnt == z.size() ){
		for( int y = 0; y < 9; ++y ){
			for( int x = 0; x < 9; ++x ){
				printf("%d ",check[cnt][y][x]);
			}
			printf("\n");
		
		return 1;
	}
	int able[10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	for( int y = 0; y < 9; ++y ){
		for( int x = 0; x < 9; ++x ){
			int tmp = check[cnt][y][x];
			check[cnt+1][y][x] = tmp;
			if( tmp == 0 ){
				continue;
			} else if( able[tmp] == 0 ){
				continue;
			} else if( zx == x || zy == y || ( zx/3*3 <= x && x < (zx/3+1)*3 ) && ( zy/3*3 <= y && y < (zy/3+1)*3 ) ){
				able[tmp] = 0;
			}
		}
	}
	for( int i = 1; i <= 9; ++i ){
		if( able[i] ){
			check[cnt+1][zy][zx] = i;
			if( find(cnt+1) ){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	for( int y = 0; y < 9; ++y ){
		for( int x = 0; x < 9; ++x ){
			scanf("%d",&check[0][y][x]);
			if( check[0][y][x] == 0 ){
				pos p = { y, x };
				z.push_back(p);
			}
		}
	}
	find(0);
	return 0;
}
