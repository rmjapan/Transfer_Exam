//
//  main.c
//  H25(3)
//
//  Created by 水野桃夏 on 2020/03/22.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>

int count=0,ccount=0;

//int f1(int x,int y){
//    int r;
//    for(r=0;y>0;y--)
//        r=r+x;
//    return r;
//}
//int f2(int x,int y){
//    int r;
//    for(r=x;y>0;y--){
//        r++;
////        count++;
//    }
//    return r;
//}
//int f3(int x,int y){
//    int r;
//    for(r=0;y>0;y--){
//        r=f2(r,x);
////        count++;
//    }
//    return r;
//}
int f4(int x,int y){
    int r;
    for(r=0;y>0;y=y/2){
        if(y%2==1){
            r=r+x;
//            count++;
        }
        x=x*2;
//        ccount++;
    }
    return r;
}
//int g(int x,int y,int r){
//    if(y==0){
//        return r;
//    }else{
//        return g(x,y-1,x+r);
//    }
//}
//int f5(int x,int y){
//    return g(x,y,0);
//}
int f6(int x,int y){
    if(y==0){
        return 0;
    }else if(y%2==1){
        return x+f6(x*2,y/2);
    }else{
        return f6(x*2,y/2);
    }
}
int main() {
    printf("%d,%d\n",f4(22,33),f6(22,33));
    return 0;
}
