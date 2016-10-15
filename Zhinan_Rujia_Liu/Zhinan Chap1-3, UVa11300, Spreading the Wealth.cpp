#include <cstdio>
#include <cstdlib>
#include <algorithm>
const int maxn = 1e6+10;
#define REP(a,b) for(i=(a); i<=(b); i++)
unsigned long long a[maxn];
long long b[maxn];
unsigned long long sum;

int main(){
  int n, i, j;
  while (scanf("%d", &n) != -1 && n){
    a[0] = b[0] = sum = 0;
    REP (1,n)
      scanf("%lld", a+i);
    REP (2,n-1)
      a[i] += a[i-1];
    sum = a[n-1] + a[n];
    sum /= n;
    REP (1, n-1)
      b[i] = a[i] - i*sum;
    // printf("sum is %llu\n",sum);
    std::sort(b, b+n);  //a[kase] not included
    // REP(1, n)
      // printf("%lld ", b[i]);
    sum = 0;
    j = b[(n-1)/2];
    REP(0, n-1)
      sum += std::abs(b[i]-j);
    printf("%llu\n", sum);
  }
  return 0;
}