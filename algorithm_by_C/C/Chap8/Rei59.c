/*
 * ----------------------
 *       軸測投影       *
 * ----------------------
 */

#include "glib.h"

void rotate(double,double,double,double,double,double,double *,double *);

void main(void)
{
    struct {
        int f;
        double x,y,z;
    } a[]
    ={-1,80,50,100,   1,0,50,100,   1,0,0,100,    1,80,0,100,
      1,80,0,0,       1,80,50,0,    1,80,50,100,  1,80,0,100,
      -1,0,50,100,    1,0,50,0,     1,0,0,0,      1,0,0,100,
      -1,0,50,0,      1,80,50,0,    -1,0,0,0,     1,80,0,0,
      -1,0,50,100,    1,40,80,100,  1,80,50,100,  -1,0,50,0,
      1,40,80,0,      1,80,50,0,    -1,40,80,100, 1,40,80,0,
      -1,50,72,100,   1,50,90,100,  1,65,90,100,  1,65,61,100,
      1,65,61,80,     1,65,90,80,   1,50,90,80,   1,50,90,100,
      -1,65,90,100,   1,65,90,80,   -1,50,90,80,  1,50,72,80,
      1,65,61,80,     -1,50,72,100, 1,50,72,80,   -999,0,0,0  };

    int k;
    double ax=20*3.14159/180,
           ay=-45*3.14159/180,
           az=0*3.14159/180,
           px,py;

    ginit(); cls();
    window(-160,-100,160,100);

    for (k=0;a[k].f!=-999;k++){
        rotate(ax,ay,az,a[k].x,a[k].y,a[k].z,&px,&py);
        if (a[k].f==-1)          // 始点なら
            setpoint(px,py);
        else
            moveto(px,py);
    }
}
void rotate(double ax,double ay,double az,double x,double y,double z,
       double *px,double *py)      // ３次元回転変換
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);        // ｙ軸回り
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                         // ｘ軸回り
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);     // ｚ軸回り
    *py=x2*sin(az)+y2*cos(az);
}
