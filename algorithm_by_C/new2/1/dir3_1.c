/*
 * ----------------------------
 *      順位付け（改良版）    *
 * ----------------------------
 */

#include <stdio.h>

#define Num 10
#define Max 100
#define Min 0

void main(void)
{
	int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
	int i, juni[Max + 2];

  //init
  for(int i =0;i<=Max;i++) juni[i] = 0;
  for(int i = 0; i<Num; i++) juni[a[i]]++;

  juni[Max+1] = 1;
  for(int i = Max+1; i>0; i--){ //Max->1に対して，右の値を左に足していく
    juni[i-1] += juni[i];
  }
	printf("  score  rank\n");
	for (i = 0; i < Num; i++)
	{
		printf("%6d%6d\n", a[i], juni[a[i]+1]);
	}
}
