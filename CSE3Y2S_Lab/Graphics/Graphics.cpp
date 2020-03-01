#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xmin, xmax, ymin, ymax;

int ComputeCode(double x, double y)
{
    int code = 0;
    if(x < xmin)
        code |= LEFT;
    else if(x > xmax)
        code |= RIGHT;
    if(y < ymin)
        code |= BOTTOM;
    else if(y > ymax)
        code |= TOP;
    return code;
}

void CohenSutherlandLineClip(double x0, double y0, double x1, double y1)
{
    int code0 = ComputeCode(x0, y0);
    int code1 = ComputeCode(x1, y1);

    int ac = 0;
    while(1)
    {
        if(code0&code1)
            break;
        else if(!(code0|code1))
        {
            ac = 1;
            break;
        }
        else
        {
            double x, y;
            int outcode = code0 ? code0 : code1;

            if(outcode & LEFT)
            {
                x = xmin;
                y = y0 + (y1-y0)*(xmin-x0)/(x1-x0);
            }
            else if(outcode & RIGHT)
            {
                x = xmax;
                y = y0 + (y1-y0)*(xmax-x0)/(x1-x0);
            }
            else if(outcode & BOTTOM)
            {
                x = x0 + (x1-x0)*(ymin-y0)/(y1-y0);
                y = ymin;
            }
            else if(outcode & TOP)
            {
                x = x0 + (x1-x0)*(ymax-y0)/(y1-y0);
                y = ymax;
            }

            if(outcode == code0)
            {
                x0 = x, y0 = y;
                code0 = ComputeCode(x0, y0);
            }
            else
            {
                x1 = x, y1 = y;
                code1 = ComputeCode(x1, y1);
            }
        }
    }

    if(ac)
    {
        cout<<"Accept this line\n";
        setcolor(RED);
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(GREEN);
        line(x0, y0, x1, y1);
    }
    else
        cout<<"Reject this line\n";
}

int main()
{
    //freopen("CohenSuterland.txt","r",stdin);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0, y0, x1, y1; //100 500 10 300 50 50 600 90
    cin>>xmin>>xmax>>ymin>>ymax;
    cin>>x0>>y0>>x1>>y1;
    CohenSutherlandLineClip(x0, y0, x1, y1);

    getch();
    return 0;
}
