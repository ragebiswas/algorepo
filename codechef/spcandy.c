#include <stdio.h>
#include <stdint.h>

int main() {
  int64_t n, k, nc, stud, teach;
  scanf("%lld", &nc);
  while(nc--) {
    scanf("%lld%lld", &n, &k);
    if(k == 0) {
      teach = n;
      stud = 0;
    }
    else {
      stud = n/k;
      teach = n%k;
    }
    printf("%lld %lld\n", stud, teach);
  }
  return 0;
}
