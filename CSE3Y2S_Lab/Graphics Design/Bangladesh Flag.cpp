//Anik_Modak
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    //Trianglr
    /*setfillstyle(LTSLASH_FILL, BLUE);
    line(100, 200, 300, 200);
    line(100, 200, 200, 0);
    line(200, 0, 300, 200);
    floodfill(102, 198, WHITE);*/

    //Circle
    setfillstyle(SOLID_FILL, RED);
    circle(275, 175, 75);
    floodfill(302, 202, WHITE);

    //Rectangle
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(100, 50, 500, 300);
    floodfill(402, 202,  WHITE);

    line(100, 50, 100, 500);

    getch();
    closegraph();
    return 0;
}


