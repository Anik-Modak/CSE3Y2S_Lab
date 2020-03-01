#include<graphics.h>
#include<iostream>
using namespace std;

void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    dx = x1 - x0;
    dy = y1 - y0;

    x = x0, y = y0;
    p = 2*dy - dx;

    while(x < x1)
    {
        if(p < 0)
        {
            p = p + 2*dy;
            putpixel(x, y, RED);
        }
        else
        {
            p = p + 2*dy - 2*dx;
            putpixel(x, y, RED);
            y++;
        }
        x++;
    }
}

int main()
{
    //freopen("BresenhamLine.txt","r",stdin);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0, y0, x1, y1; //100 100 200 200
    cout<<"Enter co-ordinates of first point: ";
    cin>>x0>>y0;

    cout<<"\nEnter co-ordinates of second point: ";
    cin>>x1>>y1;
    drawline(x0, y0, x1, y1);

    getch();
    return 0;
}
