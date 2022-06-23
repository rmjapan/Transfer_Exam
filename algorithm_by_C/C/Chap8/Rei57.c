/*
 * -------------------
 *      対称移動     *
 * -------------------
 */

#include "glib.h"

void mirror(int flag,double m,double *dat);
void draw(double *);

void main(void)
{
    double a[]={11,0,80,5,75,17,80,20,60,15,55,0,55,
                 0,20,10,40,20,40,10,20,0,20};
    ginit(); cls(); window(-160,-100,160,100);

    draw(a);
    mirror(1,0.0,a);draw(a);
    mirror(0,0.0,a);draw(a);
    mirror(1,0.0,a);draw(a);
}
void mirror(int flag,double m,double *dat)    // 対称移動
{
    int i;
    for (i=1;i<=2*dat[0];i=i+2){    // dat[0]はデータ数
        if (flag==1)                // ｙ軸中心
            dat[i]=2*m-dat[i];
        if (flag==0)                // ｘ軸中心
            dat[i+1]=2*m-dat[i+1];
    }
}
void draw(double *dat)              // 図形の描画
{
    int i;
    setpoint(dat[1],dat[2]);        // 始点
    for (i=3;i<=2*dat[0];i=i+2)     // dat[0]はデータ数
        moveto(dat[i],dat[i+1]);
}
