/*
 * -------------------------------
 *      シェルピンスキー曲線     *
 * -------------------------------
 */

#include "glib.h"

void sierpin(int,double);

void main(void)
{
    int i,n =3,         // 次数
        leng=10;        // 長さ

    ginit(); cls();

    setpoint(350,300);setangle(-45);
    for (i=0;i<4;i++){
        move(leng);
        sierpin(n,leng);
    }
}
void sierpin(int n,double l)
{
    if (n==0){
        turn(-90);
        return;
    }
    sierpin(n-1,l);move(l);
    sierpin(n-1,l);turn(135);move(l);
    turn(135);sierpin(n-1,l);move(l);
    sierpin(n-1,l);
}
