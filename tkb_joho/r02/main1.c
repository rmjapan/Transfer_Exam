//
//  main.c
//  r02(3)
//
//  Created by æ°´é‡Žæ¡?å¤? on 2020/07/23.
//  Copyright Â© 2020 æ°´é‡Žæ¡?å¤?. All rights reserved.
//

#include <stdio.h>
#define M 3
int count=0;
int count2=0,count3 = 0;

double e(double x,int n){
    if(n==0)
        return 1;
    else
        count++;
        return x*e(x,n-1);
}

double e1(double x,int n){
    int i;
    double r=1;
    for(i=0;i<n;i++){
        r=r*x;
    }
    return r;
}

double calc3(double p[], double x){
    int i;
    double r = p[M];
    for (i = 1; i <= M; i++){
        r = r * x + p[M - i];
        count3++;
    }
    return r;
}

double calc(double p[],double x){
    int i;
    double r=0;
    for(i=0;i<=M;i++){
        count++;
        r=r+p[i]*e(x,i);
        printf("%f\n",r);
    }
    return r;
}

double calc2(double p[],double x){
    int i;
    double r=p[0],s=1;
    for(i=1;i<=M;i++){
        count2++;
        s=s*x;
        r=r+p[i]*s;
        //printf("%f\n",r);
    }
    return r;
}

int main(int argc, const char * argv[]) {
    double p[4]={1,1,1,1};
//    printf("%f\n",calc(p,3));
//    printf("%d \n",count);
//    count=0;
    printf("%f\n", calc2(p, 3));
    printf("%d \n", count2);
    printf("%f\n", calc3(p, 3));
    printf("%d\n", count3);

    count=0;
//    double q[5]={1,1,1,1,1};
//    calc(q,3,5);
//    printf("%d \n",count);
//    count=0;
//    double r[6]={1,1,1,1,1,1};
//    calc(r, 3, 6);
//    printf("%d \n",count);
//    count=0;
//    double s[7]={1,1,1,1,1,1,1};
//    calc(s,3,7);
//    printf("%d \n",count);
    return 0;
}
