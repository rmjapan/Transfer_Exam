/**
*    created by: shosei
*    2022.05.09. 12:16:44
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

/*
入力例:
5
90 80 40 60 90
*/

int ccount(char str[], char c){
	int cnt = 0, i = 0;
	while(str[i] != '\0'){
		if(str[i] == c) cnt++;
		i++;
	}
	return cnt;
}

int main()
{
  int x[100], i, n;
  float s, ss, a, sigma2;
  scanf("%d", &n);

  for(i = 0; i<n; i++)
    scanf("%d", &x[i]);
  s=ss=0.0;
  for(i = 0; i<n; i++)
    s+= x[i];
  a =  s/n;

  for(i = 0; i<n; i++)
    ss += (x[i]-a)*(x[i]-a);
  sigma2 = ss/n;
  printf("%f %f\n", a, sigma2);
  //   for (i = 0; i < n; i++) {
  //   s += x[i];
  //   ss += x[i] * x[i];
  // }
  // a = s / n;
  // sigma2 = ss / n - a * a;
  // printf("%f %f\n", a, sigma2);

  printf("count : %d\n", ccount("shoseisan", 's'));
  return 0;
}