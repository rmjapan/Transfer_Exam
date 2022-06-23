/*
 * -------------------------
 *      樹木曲線その１     *
 * -------------------------
 */

#include "glib.h"

void tree(int,double,double,double,double);

double scale,branch;

void main(void)
{
    int n;
    double x0,y0,leng,angle;

    n=8;                // 枝の次数
    x0=300.0;y0=50.0;   // 根の位置
    leng=100.0;         // 枝の長さ
    angle=90.0;         // 枝の向き
    scale=1.4;          // 枝の伸び率
    branch=20.0;        // 枝の分岐角

    ginit(); cls();
    tree(n,x0,y0,leng,angle);
}
void tree(int n,double x0,double y0,double leng,double angle)
                                        // 樹木曲線の再帰手続き
{
    if (n==0)
        return;

    setpoint(x0,y0); setangle(angle);
    move(leng);

    x0=LPX; y0=LPY;
    tree(n-1,x0,y0,leng/scale,angle-branch);
    tree(n-1,x0,y0,leng/scale,angle+branch);
}
