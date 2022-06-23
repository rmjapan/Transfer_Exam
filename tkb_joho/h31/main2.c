//
//  main.c
//  H31(4)
//
//  Created by æ°´é‡Žæ¡?å¤? on 2020/04/07.
//  Copyright Â© 2020 æ°´é‡Žæ¡?å¤?. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define L_VEC 3
#define N_VEC 5
double inputs[N_VEC][L_VEC] = {{0.0, 1.0, 2.0}, {1.0, 0.0, 2.0}, {2.0, 1.0, 0.0}, {1.0, 3.0, 1.0}, {1.0, 2.0, 3.0}};

double in_prod(double *v_a, double *v_b)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < L_VEC; i++)
        sum = sum + v_a[i] * v_b[i];
    return sum;
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
    double best_value = -2.0;
    for (i = 0; i < N_VEC - 1; i++)
    {
        for (j = i + 1; j < N_VEC; j++)
        {
            sim = cos_sim(inputs[i], inputs[j]);
            if (sim > best_value)
            {
                best_value = sim;
                best_pair[0] = i;
                best_pair[1] = j;
            }
        }
    }
    printf("best:cos_sim(inputs[%d],inputs[%d])=%f\n", best_pair[0], best_pair[1], best_value);
    double a;
    a = cos_sim(inputs[0], inputs[1]);
    printf("%f", a);
    return 0;
}
