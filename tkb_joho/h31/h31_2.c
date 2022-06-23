/**
*    author:  shosei
*    created: 10.05.2021 22:38:31
**/
#include <stdio.h>
#include <math.h>

#define L_VEC 3
#define N_VEC 5
double inputs[N_VEC][L_VEC] = {
    {0, 1, 2},
    {1, 0, 2},
    {1, 0, 2},
    {1, 3, 1},
    {1, 2, 3},
};

//内積計算関数
double in_prod(double *v_a, double *v_b)
{
  int i;
  double sum = 0.0;
  for (i = 0; i < L_VEC; i++)
    sum += (*(v_a + i)) * (*(v_b + i));
}

double cos_sim(double *v_a, double *v_b)
{
  return in_prod(v_a, v_b) / (sqrt(in_prod(v_a, v_a)) * sqrt(in_prod(v_b, v_b)));
}

int main()
{
  int i, j;
  double sim;
  int best_pair[2];
  double best_value = -2.0; //最小値-1よりも小さく設定
  for (i = 0; i < N_VEC; i++)
  {
    for (j = i + 1; j < L_VEC; j++)
    {
      sim = cos_sim(inputs[i], inputs[j]); //分かりにくいがアドレス
      if (best_value < sim)
      {
        best_value = sim;
        best_pair[0] = i;
        best_pair[1] = j;
      }
    }
  }

  printf("best: cos_sim(inputs[%d], inputs[%d]) = %f\n", best_pair[0], best_pair[1], best_value);
  return 0;
}