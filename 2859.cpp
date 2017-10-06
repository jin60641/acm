#include<stdio.h>

int max( int a, int b ){
	return a>b?a:b;
}

int chk[2][10080],start[2],week[2];
const char day[7][10] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
int main(){
	for( int i = 0; i < 2; ++i ){
		int t,h,m;
		scanf("%d:%d",&h,&m);
		t = h*60+m;
		start[i] = t;
		for( int j = 0; j < 10080; ++j ){
			chk[i][j] = -1;
		}
	}
	for( int i = 0; i < 2; ++i ){
		int t,h,m;
		scanf("%d:%d",&h,&m);
		t = h*60+m;
		chk[i][start[i]] = 0;
		int k = (start[i]+t)/10080;
		int j = (start[i]+t)%10080;
		do {
			chk[i][j] = k;
			k += (j+t)/10080;
			j = (j+t)%10080;
			if( k < 5 )
			printf("%d %d\n",k,j);
		} while( chk[i][j] == -1 );
		week[i] = k;
		printf("%d\n",k);
	}
	int min = -1;
	int index;
	for( int i = 0; i < 10080; ++i ){
		if( chk[0][i] >= 0 && chk[1][i] >= 0 ){
			int cycle = max( chk[0][i], chk[1][i] );
			if( min == -1 || cycle < min ){
				min = cycle;
				index = i;
			}
		}
	}
	if( min == -1 ){
		printf("Never\n");
	} else {
		printf("%s\n",day[index/1440]);
		printf("%d %d %02d:%02d\n",chk[0][index],chk[1][index],(index%1440)/60,index%60);
	}
	return 0;
}
