/*
 * -----------------------
 *       コッホ曲線      *
 * -----------------------
 */

#include "glib.h"

void koch(int,double);

void main(void)
{
    int    n=4;         // コッホ次数
    double leng=4.0;    // ０次の長さ

    ginit(); cls();
    setpoint(100,200);
    setangle(0);

    koch(n,leng);
}
void koch(int n,double leng)        // コッホ曲線の再帰手続き
{
    if (n==0){
        move(leng);
    }
    else {
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
        turn(-120);
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
    }
}
