#include<stdio.h>

double fn(double x, double a[], int n){
  double f_n = 0;
  for (int i = 0; i <= n; i++){
    f_n = f_n * x + a[n-i];
  }
  return f_n;
}
int main(){
  double a[] = {1, 2, 3, 4, 5};
  int n = sizeof(a) / sizeof(double);
  for (int x = 0; x <= n; x++)
  {
    printf("f_%d = %lf\n",x,  fn(x,a,n-1));
  }
    return 0;
}
