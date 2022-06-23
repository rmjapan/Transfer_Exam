/*
 * -------------------------
 *      ヒルベルト曲線     *
 * -------------------------
 */

#include "glib.h"

void hilbert(int,double,double);

void main(void)
{
    int n=4;         // 次数

    ginit(); cls();

    setpoint(200,100);
    hilbert(n,10,90);
}
void hilbert(int n,double l,double angle)
{
    if (n==0)
        return;
    turn(angle);hilbert(n-1,l,-angle);move(l);
    turn(-angle);hilbert(n-1,l,angle);move(l);
    hilbert(n-1,l,angle);turn(-angle);move(l);
    hilbert(n-1,l,-angle);turn(angle);
}
