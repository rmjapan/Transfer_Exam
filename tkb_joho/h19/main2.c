//
//  main.c
//  h19(4)
//
//  Created by 水野桃夏 on 2020/04/18.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>

char digits[]="0123456789";

void pr(int x){
    if(x>=10)
        pr(x/10);
    putchar(digits[x%10]);
}

void pr2(int x){
    int i,d[20];
    i=0;
    while(x>=10){
        d[i]=x%10;
        x=x/10;
        i++;
    }
    putchar(digits[x]);
    while(--i>=0)
        putchar(digits[d[i]]);
}

int is_symmetric(char string[]){
    int i=0,j=0;
    while(string[i]!=0)
        i++;
    while(string[j]==string[i-1]){
        j++; i--;
        if(j>i||j==i-1)
            return 1;
    }
    return 0;
}

int is_symmetric2(char string[]){
    int i=0,k,l;
    while(string[i]!='\0')
        i++;
    l=i-1;
    k=0;
    while(k<(i/2)){
        if(string[k]==string[l]){
            k++;l--;
        }else{
            return 0;
        }
    }
    return 1;
}


int f(int m,int n){
    int a,b,x[50];
    x[0]=1;
    for(a=1;a<=m;a++){
        x[a]=0;
        for(b=a;b>0;b--)
            x[b]=x[b-1]+x[b];
    }
    return x[n];
}

int g(int m,int n){
    int a,b,x[50];
    for(b=0;b<=n;b++)
        x[b]=1;
//    for(a=1;a<=m;a++)
    for(a=1;a<=n;a++)
        for(b=1;b<=n;b++)
            x[b]=x[b-1]+x[b];
    return x[n];
}

int main(int argc, const char * argv[]) {
    char a[]="djbvifu";
    char b[]="akuhuka";
    char c[]="nvudkkduvn";
    printf("%d\n%d\n%d\n",is_symmetric2(a),is_symmetric2(b),is_symmetric2(c));
//    pr(1384);
//    pr2(1384);
    printf("%d\n%d\n",f(10,6),g(10,6));
    return 0;
}
