/*
 * -------------------------------
 *      正Ｎ角形（ポリゴン）     *
 * -------------------------------
 */

#include "glib.h"

void main(void)
{
    int j,n;

    ginit();cls();

    for (n=3;n<=9;n++){
        setpoint(200,50);
        setangle(0);
        for (j=0;j<n;j++){
            move(80);
            turn(360/n);
        }
    }
}
