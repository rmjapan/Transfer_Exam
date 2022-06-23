/*
 * ------------------------------
 *       クロス・ステッチ       *
 * ------------------------------
 */

#include "glib.h"

void stech(int,double);

void main(void)
{
    int    k,
           n=4;         // ステッチの次数
    double leng=2.0;    // ０次の長さ

    ginit(); cls();
    setpoint(200,300); setangle(0);
    for (k=1;k<=4;k++){
        stech(n,leng);
        turn(-90);
    }
}
void stech(int n,double leng)       // ステッチの再帰手続き
{
    if (n==0)
        move(leng);
    else {
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(-90);
        stech(n-1,leng); turn(-90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng);
    }
}
