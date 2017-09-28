#include<stdio.h>
long long int max( long long int a, long long int b ){
	return a>b?a:b;
}
long long int last = 0;
long long int nums[1000001];

struct range {
	long long int l,r,sum;
};

range ranges[(1<<21)+1]; // 최악의 경우는 2의 멱수승!

void make(long long int index, long long int left, long long int right){
	last = max(last,index);
	ranges[index].l = left;
	ranges[index].r = right;
	long long int cnt = right-left+1;
	if( cnt == 1 ){ // left == right
		ranges[index].sum = nums[left];
	} else {
		long long int mid = (left+right)/2;
		make(index*2,left,mid);
		make(index*2+1,mid+1,right);
	}
}

long long int update(long long int now, long long int target){
	long long int cnt = ranges[now].r - ranges[now].l + 1;
	if( cnt == 1 ){
		long long int tmp = ranges[now].sum;
		ranges[now].sum = nums[target];
		return (ranges[now].sum - tmp);
	} else {
		long long int left = now*2;
		long long int right = now*2+1;
		long long int change;
		if( ranges[left].l <= target && target <= ranges[left].r ){
			change = update(left,target);
		} else if( ranges[right].l <= target && target <= ranges[right].r ){
			change = update(right,target);
		}
		ranges[now].sum += change;
		return change;
	}
}

long long int get(long long int now,long long int start,long long int end){
	if( ranges[now].l == start && ranges[now].r == end ){
		return ranges[now].sum;
	}
	long long int left = now*2;
	long long int right = now*2+1;
	if( ranges[left].l <= start && start <= ranges[left].r ){
		if( end <= ranges[left].r ){
			return get(now*2,start,end);
		} else {
			return get(now*2,start,ranges[left].r) + get(now*2+1,ranges[right].l,end);
		}
	} else {
		return get(now*2+1,start,end);
	}
}

int main(){
	long long int N,M,K;
	scanf("%lld %lld %lld",&N,&M,&K);
	for( long long int i = 1; i <= N; ++i ){
		scanf("%lld",&nums[i]);
	}
	make(1,1,N);
	for( long long int i = last; i >= 1; --i ){
		if( ranges[i].l >= 1 && ranges[i].r >= 1 ){
			ranges[i/2].sum += ranges[i].sum;
		}
	}
	for( long long int i = 0; i < M+K; ++i ){
		long long int type,a,b;
		scanf("%lld %lld %lld",&type,&a,&b);
		if( type == 1 ){ // 변경
			nums[a] = b;
			update(1,a);
		} else if( type == 2 ){ // 구간합
			printf("%lld\n",get(1,a,b));
		}
	}
	return 0;
}
