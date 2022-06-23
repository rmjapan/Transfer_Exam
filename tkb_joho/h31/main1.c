//
//  main.c
//  h31(1)
//
//  Created by 水野桃夏 on 2020/04/07.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#define X_SIZE 7
#define Y_SIZE 5
int maze[X_SIZE][Y_SIZE]={{1,1,1,1,1},{0,0,0,0,1},{1,1,1,0,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,0},{1,1,1,1,1}}; //1は壁,0は通路.

int dist[X_SIZE][Y_SIZE];   //入り口からの距離を入れる.

int ok(int x,int y){    //通路であれば1,壁なら0を返す.
    if(maze[x][y])
        return 0;
    else
        return 1;
}
void init_dist(void){   //初期化.
    int x,y;
    for(x=0;x<X_SIZE;x++)
        for(y=0;y<Y_SIZE;y++)
            dist[x][y]=X_SIZE*Y_SIZE;
}
int update_dist(int x1,int y1,int x2,int y2){   //値の書き換えがあれば1,なければ0を返す.
    if(ok(x1, y1)==1&&ok(x2, y2)==1&&dist[x2][y2]>dist[x1][y1]+1){
        dist[x2][y2]=dist[x1][y1]+1;
        return 1;
    }
    return 0;
}
int main() {    //入り口から迷路のマスの距離を求める.
    int changed;    //配列distの値に変化があった座標の数をchangedに加える.
    int x,y;
//    int a;
    init_dist();
    dist[1][0]=0; //スタートを0にする.
//    a=update_dist(1, 0, 1, 1);
    do{
        changed=0;
        for(y=0;y<Y_SIZE;y++){
            for(x=0;x<X_SIZE;x++){
                    changed=changed+update_dist(x, y, x, y+1);
                    changed=changed+update_dist(x, y, x, y-1);
                    changed=changed+update_dist(x, y, x+1, y);
                    changed=changed+update_dist(x, y, x-1, y);
            }
        }
    }while(changed);
    for(y=0;y<Y_SIZE;y++){
        for(x=0;x<X_SIZE;x++){
            printf("%d ",dist[x][y]);
        }
        printf("\n");
    }
//    printf("%d\n%d",dist[1][0],dist[1][1]);
    return 0;
}
