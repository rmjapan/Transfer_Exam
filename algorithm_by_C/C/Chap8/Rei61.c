/*
 * --------------------
 *     ３次元関数     *
 * --------------------
 */

#include "glib.h"

void main(void)
{
    double x,y,z,px,py,ax,ay,rd=3.1415927/180;
    ax=30*rd;
    ay=-30*rd;

    ginit(); cls();
    window(-320,-200,320,200);

    for (z=200.0;z>=-200.0;z=z-10.0){
        for (x=-200.0;x<=200.0;x=x+5.0){
        y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
        px=x*cos(ay)+z*sin(ay);        // 回転変換
        py=y*cos(ax)-(-x*sin(ay)+z*cos(ay))*sin(ax);
        if ((int)x==-200)
            setpoint(px,py);
        else
            moveto(px,py);
        }
    }
}
