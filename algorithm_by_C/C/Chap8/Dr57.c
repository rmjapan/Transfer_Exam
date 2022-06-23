/*
 * ------------------------
 *     ２次元回転変換     *
 * ------------------------
 */

#include "glib.h"

void multi(double,double,double *,double *);
void rotate(double,double *,double *);

void main(void)
{
    double x[]={0,100,100,  0,0},
           y[]={0,  0,200,200,0};
    int j,k,n=5;

    ginit(); cls(); window(-320,-200,320,200);

    for (j=0;j<12;j++){
        for (k=0;k<n;k++){
            multi(.8,.8,&x[k],&y[k]);
            rotate(30,&x[k],&y[k]);
            if (k==0)
                setpoint(x[k],y[k]);
            else
                moveto(x[k],y[k]);
        }
    }
}
void multi(double factx,double facty,double *x,double *y)
{
    *x=factx*(*x);
    *y=facty*(*y);
}
void rotate(double deg,double *x,double *y)	// 回転変換
{
    double dx,dy,rd=3.14159/180;
    dx=(*x)*cos(deg*rd)-(*y)*sin(deg*rd);
    dy=(*x)*sin(deg*rd)+(*y)*cos(deg*rd);
    *x=dx; *y=dy;
}
