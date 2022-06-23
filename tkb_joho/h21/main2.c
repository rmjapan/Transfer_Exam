//
//  main.c
//  h21(4)
//
//  Created by 水野桃夏 on 2020/04/20.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>

void print_array(int a[],int n){
    int i;
    for(i=0;i<n-1;i++)
        printf("%d,",a[i]);
    printf("%d\n",a[n-1]);
}

void sort(int a[],int n){
    int i,j,tmp;
    for(i=1;i<n;i++){
        for(j=i;j>0&&a[j-1]>a[j];j--){
            tmp=a[j];
            a[j]=a[j-1];
            a[j-1]=tmp;
            print_array(a,n);
        }
    }
}

void check_swap(int a[],int i,int j){
    int tmp;
    if(a[i]>a[j]){
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
}

void sort4(int a[]){
    check_swap(a, 0, 3);
    check_swap(a, 1, 2);
    check_swap(a, 2, 3);
    printf("%d\n",a[3]);
    check_swap(a, 0, 1);
    check_swap(a, 1, 2);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[4]={4,3,2,1};
    sort4(a);
    return 0;
}
