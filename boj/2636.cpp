#include<stdio.h>
int a[100][100];
int day = 0;
int min = 0;
int cnt = 0;
int check[100][100];
int Y,X;
int dfs(int y,int x){
    if( check[y][x] == day ){
        return 0;
    } else if( a[y][x] == -1 ){
        check[y][x] = day;
        a[y][x] = day+1;
        --cnt;
        return 0;
    } else if( a[y][x] == 0 ){
        a[y][x] = day;
    }
    check[y][x] = day;
    if( y < Y-1 ){
        dfs(y+1,x);
    }
    if( y > 0 ){
        dfs(y-1,x);
    }
    if( x < X-1 ){
        dfs(y,x+1);
    }
    if( x > 0 ){
        dfs(y,x-1);
    }
    return 0;
}

int main(){
    scanf("%d %d",&Y,&X);
    for( int i = 0; i < Y; ++i ){
        for( int j = 0; j < X; ++j ){
            scanf("%d",&a[i][j]);
            if( a[i][j] == 1 ){
                a[i][j] = -1;
                ++cnt;
            }
        }
    }
    a[0][0] = 1;
    while( cnt > 0 ){
        min = cnt;
        ++day;
        for( int i = 0; i < Y; ++i ){
            for( int j = 0; j < X; ++j ){
                if( a[i][j] == day && check[i][j] != day ){
                    dfs(i,j);
                }
            }
        }
    }
    printf("%d\n%d\n",day,min);
    return 0;
}


