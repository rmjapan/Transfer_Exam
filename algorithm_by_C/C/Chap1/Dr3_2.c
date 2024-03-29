﻿/*
 * -----------------------------------
 *       ・ｽ・ｽ・ｽﾊ付・ｽ・ｽ・ｽi・ｽ・ｽ・ｽﾌデ・ｽ[・ｽ^・ｽﾅ）    *
 * -----------------------------------
 */

#include <stdio.h>

#define Num 10
#define Max 36
#define Min -20
#define Bias 1 - (Min) // ・ｽﾅ擾ｿｽ・ｽl・ｽ・ｽz・ｽ・ｽv・ｽf・ｽﾌ１・ｽﾉ対会ｿｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ

void main(void)
{
	int a[] = {-3, 2, 3, -1, -2, -6, 2, -1, 1, 5};
	int i, juni[Max + Bias + 1];

	for (i = Min + Bias; i <= Max + Bias; i++)
		juni[i] = 0;

	for (i = 0; i < Num; i++)
		juni[a[i] + Bias]++;

	juni[0] = 1;
	for (i = Min + Bias; i <= Max + Bias; i++){
		juni[i] = juni[i] + juni[i - 1];
	}

	for (i = 0; i < Num; i++)
		printf("%6d%6d\n", a[i], juni[a[i] + Bias - 1]);
}
