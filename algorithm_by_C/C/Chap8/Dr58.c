/*
 * -------------------
 *      √２分割     *
 * -------------------
 */

#include "glib.h"

void main(void)
{
    int k;
    double leng=400.0,            // 対角線の初期値
           rd=3.14159/180,
           x,y;

    ginit(); cls();
    setpoint(0,380); setangle(-54.7);
    for (k=1;k<=10;k++){
        move(leng);                 // 対角線を引く
        x=leng*cos(54.7*rd);        // ｘ方向の長さ
        y=leng*sin(54.7*rd);        // ｙ方向の長さ
        turn(180-35.3); move(y);    // 長方形を描く
        turn(90); move(x);
        turn(90); move(y);
        turn(90); move(x);
        turn(35.3);
        leng=leng/sqrt(2.0);
    }
}
