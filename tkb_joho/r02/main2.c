//
//  main.c
//  r02(4)
//
//  Created by 水野�??��? on 2020/07/23.
//  Copyright © 2020 水野�??��?. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int count = 0;
int res = 0;
void swap(char string[], int i, int j)
{
    char tmp=string[i];
    string[i]=string[j];
    string[j]=tmp;
}

void make_permutation(char pattern[],int n){
    if(n<=1){
        count++;

        if (pattern[strlen(pattern) - 1] == 'B' && res == 0){ //最初に右端にBが現れる回数
            res = count;
        }
        printf("%s\n", pattern);
    }else{
        int n1=n-1;
        for(int i=0;i<n;i++){
            swap(pattern, i, n1);
            make_permutation(pattern, n1);
            swap(pattern, i, n1);
        }
    }
}

void make_permutation2(char pattern[],int n){
    if(n<=1){
        printf("%s\n",pattern);
    }else{
        int n1=n-1;
        for(int i=0;i<n1;i++){
            swap(pattern, i, n1);
            make_permutation2(pattern, n1);
            swap(pattern, i, n1);
        }
        make_permutation2(pattern, n1);
    }
}

void make_permutation3(char pattern[],int n){
    if(n<=1){
        printf("%s\n",pattern);
    }else{
        int n1=n-1;
        for(int i=0;i<n;i++){
            if(i < n1) swap(pattern, i, n1);
            make_permutation2(pattern, n1);
            if(i < n1) swap(pattern, i, n1);
        }
    }
}



int main(int argc, const char * argv[]) {
    char pattern[]="ABC";
    //make_permutation(pattern, strlen(pattern));
    make_permutation3(pattern, 3);
    printf("%d", res);
    return 0;
}
