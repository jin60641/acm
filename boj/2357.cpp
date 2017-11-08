#include<stdio.h>
long long int max( long long int a, long long int b ){
	if( a == 0 ){
		return b;
	} else if( b == 0 ){
		return a;
	} else {
		return a>b?a:b;
	}
}
long long int min( long long int a, long long int b ){
	if( a == 0 ){
		return b;
	} else if( b == 0 ){
		return a;
	} else {
		return a<b?a:b;
	}
}
const int MAX = 1;
const int MIN = 0;
int last = 0;
long long int nums[100001];

struct range {
	long long int l,r,min,max;
};

range ranges[500000];

void make(int index, int left, int right){
	last = max(last,index);
	ranges[index].l = left;
	ranges[index].r = right;
	int cnt = right-left+1;
	if( cnt == 1 ){ // left == right
		ranges[index].max = nums[left];
		ranges[index].min = nums[left];
	} else {
		int mid = (left+right)/2;
		make(index*2,left,mid);
		make(index*2+1,mid+1,right);
	}
}

long long int get(int type, int now, int start, int end){
	if( ranges[now].l == start && ranges[now].r == end ){
		return ((type==MAX)?(ranges[now].max):(ranges[now].min));
	}
	long long int left = now*2;
	long long int right = now*2+1;
	if( ranges[left].l <= start && start <= ranges[left].r ){
		if( end <= ranges[left].r ){
			return get(type,now*2,start,end);
		} else {
			long long int result[2] = { get(type,now*2,start,ranges[left].r), get(type,now*2+1,ranges[right].l,end) };
			return ((type==MAX)?(max(result[0],result[1])):(min(result[0],result[1])));
		}
	} else {
		return get(type,now*2+1,start,end);
	}
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for( int i = 1; i <= N; ++i ){
		scanf("%lld",&nums[i]);
	}
	make(1,1,N);
	for( int i = last; i >= 1; --i ){
		if( ranges[i].l >= 1 && ranges[i].r >= 1 ){
			ranges[i/2].max = max(ranges[i/2].max, ranges[i].max);
			ranges[i/2].min = min(ranges[i/2].min, ranges[i].min);
		}
	}
	for( int i = 0; i < M; ++i ){
		int start,end;
		scanf("%d %d",&start,&end);
		printf("%lld %lld\n",get(MIN,1,start,end),get(MAX,1,start,end));
	}
	return 0;
}
