//
//  main.c
//  h20(4)
//
//  Created by 水野桃夏 on 2020/04/19.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>

#define N 5
int a[N][N]={{0,1,1,0,0},{1,0,0,1,0},{0,1,0,1,0},{0,0,0,0,0},{0,0,0,1,0}};

int maxrank(){
    int i,j,rank,max=0;
    for(i=0;i<N;i++){
        rank=0;
        for(j=0;j<N;j++){
            if(a[j][i]){
                rank++;
            }
        }
        if(rank>max)
            max=rank;
    }
    return max;
}

int reachable(int start,int goal){
    int i,j,visited[N],checked[N];
    for(i=0;i<N;i++){
        visited[i]=0;
        checked[i]=0;
    }
    i=start;
    while(1){
        if(i==goal)
            return 1;
        visited[i]=1;
        for(j=0;j<N;j++){
            if(a[i][j])
                checked[j]=1;
        }
        for(j=0;j<N;j++){
            if(!visited[j]&&checked[j]){
                i=j;
                break;
            }
        }
        if(j==N)
            return 0;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n",reachable(2,3));
    return 0;
}
