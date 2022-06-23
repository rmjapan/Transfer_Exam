//
//  main.c
//  h26(3)
//
//  Created by 水野桃夏 on 2020/05/12.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count1=0;
int count2=0;

unsigned int check_flag(unsigned int *flag,unsigned int p){
    return flag[p];
}

void reset_flag(unsigned int *flag,unsigned int p){
    flag[p]=0;
}

void prime1(unsigned int max){
    unsigned int p,i;
    unsigned int *flag=(unsigned int *)malloc(sizeof(unsigned int)*(max+1));

    for(p=2;p<=max;p++) flag[p]=1;

    for(p=2;p*p<=max;p++){
        if(check_flag(flag, p)!=0){
            count1++;
            for(i=p*p;i<=max;i+=p){
                reset_flag(flag, i);
                count2++;
            }
        }
    }

    for(p=2;p<=max;p++)
        if(check_flag(flag, p)!=0){
            printf("%d ",p);
            count1++;
        }
    printf("\n");
}

unsigned int check_flag2(unsigned int *flag,unsigned int p){
    return (flag[p/32]&(1<<(p%32)));
}

void reset_flag2(unsigned int *flag,unsigned int p){
    flag[p/32]=flag[p/32] ^ (1<<(p%32));
}

void prime2(unsigned int max){
    unsigned int p,i;
    unsigned int words=ceil((double)(max+1)/32);
    unsigned int *flag=(unsigned int *)malloc(sizeof(unsigned int)*words);

    for(i=0;i<words;i++)
        flag[i]=0xFFFFFFFF;

    for(p=2;p*p<=max;p++){
        if(check_flag2(flag, p)!=0){
            for(i=p*p;i<=max;i+=p)
                reset_flag2(flag,i);
        }
    }
    for(p=2;p<=max;p++)
        if(check_flag2(flag, p)!=0)
            printf("%d ",p);
    printf("\n");
    printf("%x ",flag[0]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    prime2(10);
//    printf("%d\n",count2);
    return 0;
}