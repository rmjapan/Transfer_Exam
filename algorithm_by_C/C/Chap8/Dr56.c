/*
 * ----------------------
 *      渦巻き模様      *
 * ----------------------
 */

#include "glib.h"

void main(void)
{
    double leng=200.0,    // 辺の初期値
           angle=89.0,    // 回転角
           step=1.0;      // 辺の減少値

    ginit(); cls();

    setpoint(220,100);
    setangle(0);
    while (leng>10.0){
        move(leng);
        turn(angle);
        leng=leng-step;
    }
}
