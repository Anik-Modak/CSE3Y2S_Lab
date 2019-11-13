//Anik_Modak
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setfillstyle(SOLID_FILL, BLUE);
    line(100, 200, 300, 200);
    line(100, 200, 200, 0);
    line(200, 0, 300, 200);
    floodfill(102, 198, 15);

    setfillstyle(SOLID_FILL, RED);
    circle(300, 200, 100);
    floodfill(302, 202, 15);

    setfillstyle(SOLID_FILL, GREEN);
    rectangle(300, 200, 500, 400);
    floodfill(402, 202, 15);

    getch();
    closegraph();
    return 0;
}

