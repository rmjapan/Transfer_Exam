/**
 *    created by: shosei
 *    2022.05.09. 09:02:35
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

int isprime(int n) {
  int i;

  for (i = 2; i <= n - 1; i++) {
    if (n % i == 0) return 0;  // nがiで割り切れたらnは素数ではない
  }
  return (1);
}

int isprime2(int n) {
  int i;

  i = 2;
  while (i <= n - 1) {
    if (n % i == 0) return 0;  // nがiで割り切れたらnは素数ではない
    i++;
  }
  return (1);
}

int prime_1000(){
  int count = 0, i;
  i=2;
  while(count<1000) {//countが1000より小さい間
    if(isprime(i++)) count++; //iが素数ならカウント
  }
  return (i-1); //インクリメントの調整
}

int main() {
  int n = 59;
  if (isprime2(n))
    printf("%d is prime.\n", n);
  else
    printf("%d is not prime.\n", n);

  printf("1000番目の素数:%d\n", prime_1000());

  return 0;
}