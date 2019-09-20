#include<stdio.h>
#include<algorithm>

const int MAX_N = 500001;

int N, A[MAX_N];


long long int merge(long long int start, long long int end) {
  int length = end - start + 1;
  if (length == 1) {
    return 0;
  }
  if (length == 2 && A[start] > A[end]) {
    std::sort(A + start, A + end + 1);
    return 1;
  }
  long long int mid = (start + end) / 2;
  long long int left = merge(start, mid);
  long long int right = merge(mid + 1, end);
  long long int cnt = 0;

  int i, j;
  i = start;
  j = mid+1;
  
  while(i <= mid && j <= end) {
    if (A[i] > A[j]) {
      cnt += mid + 1 - i;
      ++j;
    } else {
      ++i;
    }
  }
  std::sort(A + start, A + end + 1);
  return left + right + cnt;
}

int main() {
  scanf("%d", &N);
  for (long long int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  printf("%lld\n", merge(1, N));
  return 0;
}
