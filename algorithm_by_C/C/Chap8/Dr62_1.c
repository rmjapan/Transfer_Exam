/*
 * ---------------------
 *       コッホ島      *
 * ---------------------
 */

#include "glib.h"

void koch(int,double);

void main(void)
{
    int    i,
           n=4;         // コッホ次数
    double leng=4.0;    // ０次の長さ

    ginit(); cls();
    setpoint(150,300);
    setangle(0);
    for (i=0;i<3;i++){
          koch(n,leng);
        turn(-120);
    }
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
