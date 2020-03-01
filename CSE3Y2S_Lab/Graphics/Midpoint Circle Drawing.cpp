#include<graphics.h>
#include<iostream>
using namespace std;

void drawcircle(int x0, int y0, int r)
{
    int x = 0, y = r, p = 1-r;
    while(x < y)
    {
        putpixel(x0 + x, y0 + y, RED);
        putpixel(x0 + y, y0 + x, RED);
        putpixel(x0 - y, y0 + x, RED);
        putpixel(x0 - x, y0 + y, RED);
        putpixel(x0 - x, y0 - y, RED);
        putpixel(x0 - y, y0 - x, RED);
        putpixel(x0 + y, y0 - x, RED);
        putpixel(x0 + x, y0 - y, RED);

        x ++;
        if(p < 0)
            p = p + 2*x + 1;
        else
        {
            y --;
            p = p + 2*x + 1 - 2*y;
        }
        //delay(1);
    }
}

int main()
{
    //freopen("MidpontCircle.txt","r",stdin);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int r, x, y; //100 150 150
    cout<<"Enter radius of circle: ";
    cin>>r;

    cout<<"\nEnter co-ordinates of center(x and y): ";
    cin>>x>>y;
    drawcircle(x, y, r);

    getch();
    return 0;
}
