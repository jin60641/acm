#include<stdio.h>

int main(){
	int mon,date;
	scanf("%d %d",&mon,&date);
	int dates[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	char days[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	printf("%s",days[(dates[mon-1]+date)%7]);
	return 0;
}
