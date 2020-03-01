#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

void bezier(int x[4], int y[4])
{
    double xt, yt, t;
    for(t = 0.0; t <= 1.0; t += 0.001)
    {
        xt = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
        yt = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
        putpixel(xt, yt, RED);
        delay(1);
    }

    for(int i=0; i<4; i++)
    {
        putpixel(x[i], y[i], WHITE);
        circle(x[i],y[i], 2);
    }
}

int main()
{
    //freopen("BezierCurve.txt","r",stdin);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x[4], y[4]; //200 300 300 400 300 300 100 200
    cout<<"Enter the four control points : ";
    for(int i=0; i<4; i++)
        cin>>x[i]>>y[i];

    bezier(x, y);
    getch();
    return 0;
}
