#include <graphics.h>

const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
double xmin, xmax, ymin, ymax;

int ComputeOutCode(double x, double y)
{
    int code = 0;
    if (x < xmin)           // to the left of clip window
        code |= LEFT;
    else if (x > xmax)      // to the right of clip window
        code |= RIGHT;
    if (y < ymin)           // below the clip window
        code |= BOTTOM;
    else if (y > ymax)      // above the clip window
        code |= TOP;
    return code;
}

void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1)
{
    int outcode0 = ComputeOutCode(x0, y0);
    int outcode1 = ComputeOutCode(x1, y1);
    int accept = 0;

    while (1)
    {
        if (!(outcode0 | outcode1))
        {
            accept = 1;
            break;
        }
        else if (outcode0 & outcode1)
        {
            break;
        }
        else
        {
            double x, y;
            int outcodeOut = outcode0 ? outcode0 : outcode1;
            if (outcodeOut & TOP)
            {
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            }
            else if (outcodeOut & BOTTOM)
            {
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            }
            else if (outcodeOut & RIGHT)
            {
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            }
            else if (outcodeOut & LEFT)
            {
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            if (outcodeOut == outcode0)
            {
                x0 = x;
                y0 = y;
                outcode0 = ComputeOutCode(x0, y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                outcode1 = ComputeOutCode(x1, y1);
            }
        }
    }

    if (accept)
    {
        setcolor(RED);
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(BLUE);
        line(x0, y0, x1, y1);
    }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    xmin = 100;
    xmax = 500;
    ymin = 10;
    ymax = 300;

    double x0, y0, x1, y1;
    x0 = 50, y0 = 50, x1 = 600, y1 = 90;

    CohenSutherlandLineClipAndDraw(x0, y0, x1, y1);
    getch();
    return 0;
}
