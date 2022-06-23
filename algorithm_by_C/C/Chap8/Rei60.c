/*
 * -------------------------------------
 *      回転体モデル（ワイングラス）   *
 * -------------------------------------
 */

#include "glib.h"

void rotate(double,double,double,double,double,double,double *,double *);

void main(void)
{
    int n,k;
    double x,z,px,py,ax,ay,az,rd=3.14159/180;
    double y[]={180,140,100,60,20,10,4,0,-999},   // 高さ
           r[]={100,55,10,10,10,50,80,80,-999};   // 半径
    ax=35*rd;   // ｘ軸回りの回転角
    ay=0;       // ｙ軸回りの回転角
    az=20*rd;   // ｚ軸回りの回転角

    ginit(); cls();
    window(-320,-100,320,300);

    for (k=0;(int)y[k]!=-999;k++){    // ｙ軸回りの回転軌跡
        for (n=0;n<=360;n=n+10){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (n==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }
    for (n=0;n<=360;n=n+60){        // 稜線
        for (k=0;(int)y[k]!=-999;k++){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (k==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }
}
void rotate(double ax,double ay,double az,double x,double y,double z,
            double *px,double *py)   // ３次元回転変換
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);          // ｙ軸回り
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                           // ｘ軸回り
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);       // ｚ軸回り
    *py=x2*sin(az)+y2*cos(az);
}
