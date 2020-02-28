#include<iostream>
#include<graphics.h>
using namespace std;

void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        putpixel(x0 + x, y0 + y, RED);
        putpixel(x0 + y, y0 + x, RED);
        putpixel(x0 - y, y0 + x, RED);
        putpixel(x0 - x, y0 + y, RED);
        putpixel(x0 - x, y0 - y, RED);
        putpixel(x0 - y, y0 - x, RED);
        putpixel(x0 + y, y0 - x, RED);
        putpixel(x0 + x, y0 - y, RED);

        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

int main()
{
    freopen("MidpontCircle.txt","r",stdin);
    int gd=DETECT, gm=DETECT;
    initgraph(&gd,&gm,"");

    int r, x, y;
    cout<<"Enter radius of circle: ";
    cin>>r;

    cout<<"\nEnter co-ordinates of center(x and y): ";
    cin>>x>>y;

    drawcircle(x, y, r);
    getch();
    return 0;
}
