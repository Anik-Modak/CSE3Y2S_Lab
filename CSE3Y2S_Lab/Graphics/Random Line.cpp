#include<graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for(int i=0; i<=100; i++)
    {
        setcolor(RED);
        line(rand()%100, rand()%150, rand()%200, rand()%250);
        delay(100);
        cleardevice();

        setcolor(GREEN);
        line(rand()%200, rand()%250, rand()%300, rand()%350);
        delay(100);
        cleardevice();

        setcolor(BLUE);
        line(rand()%300, rand()%350, rand()%400, rand()%450);
        delay(100);
        cleardevice();

        setcolor(YELLOW);
        line(rand()%400, rand()%400, rand()%500, rand()%550);
        delay(100);
        cleardevice();

        setcolor(GREEN);
        line(rand()%250,rand()%350,rand()%450,rand()%550);
        setcolor(RED);
        line(rand()%350,rand()%450,rand()%350,rand()%450);
        setcolor(BLUE);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        setcolor(YELLOW);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        delay(100);
    }
    getch();
    return 0;
}
