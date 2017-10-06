#include<stdio.h>
int max( int a, int b ){
	return a>b?a:b;
}
int last = 0;

struct range {
	int l,r,whole;
	
};

range ranges[500000];

void make(int index, int left, int right){
	last = max(last,index);
	ranges[index].l = left;
	ranges[index].r = right;
	int cnt = right-left+1;
	if( cnt == 1 ){ // left == right
		ranges[index].whole = 2;
	} else {
		ranges[index].whole = 0;
		int mid = (left+right)/2;
		make(index*2,left,mid);
		make(index*2+1,mid+1,right);
	}
}


bool get(int now, int start, int end){
	if( ranges[now].l == start && ranges[now].r == end ){
		return ranges[now].whole==2;
	}
	int left = now*2;
	int right = now*2+1;
	if( ranges[left].l <= start && start <= ranges[left].r ){
		if( end <= ranges[left].r ){
			return get(now*2,start,end);
		} else {
			return get(now*2,start,ranges[left].r) && get(now*2+1,ranges[right].l,end);
		}
	} else {
		return get(now*2+1,start,end);
	}
}

void swap(int a, int b){
	
}

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	make(1,1,N);
	for( int i = last; i >= 1; --i ){
		if( ranges[i].l >= 1 && ranges[i].r >= 1 ){
			ranges[i/2].whole += ranges[i].whole/2;
		}
	}
	for( int i = 1; i <= last; ++i ){
	//	printf("%d : %d~%d // %s\n",i,ranges[i].l,ranges[i].r,ranges[i].whole==2?"YES":"NO");
	}
	for( int i = 0; i < K; ++i ){
		int type,a,b;
		scanf("%d %d %d",&type,&a,&b);
		++a;++b;
		if( type )
			printf("%s\n",get(1,a,b)?"YES":"NO");
		else swap(a,b);
	}
	return 0;
}
