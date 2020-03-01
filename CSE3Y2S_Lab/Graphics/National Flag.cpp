//Anik_Modak
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    //Circle
    setfillstyle(SOLID_FILL, RED);
    circle(275, 175, 75);
    floodfill(302, 202, WHITE);

    //Rectangle
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(100, 50, 500, 300);
    floodfill(402, 202,  WHITE);

    line(100, 50, 100, 800);

    getch();
    closegraph();
    return 0;
}
