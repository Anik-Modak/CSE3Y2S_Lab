#include<graphics.h>

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    for(int t=1; t<=50; t++)
    {
        setcolor(GREEN);
        line(rand()%450,rand()%450,rand()%450,rand()%450);
        delay(100);
        cleardevice();

        setcolor(RED);
        line(rand()%350,rand()%350,rand()%350,rand()%350);
        delay(100);
        cleardevice();

        setcolor(BLUE);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        delay(100);
        cleardevice();

        setcolor(YELLOW);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        delay(100);
        cleardevice();

        setcolor(GREEN);
        line(rand()%450,rand()%450,rand()%450,rand()%450);
        setcolor(RED);
        line(rand()%350,rand()%350,rand()%350,rand()%350);
        setcolor(BLUE);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        setcolor(YELLOW);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        delay(100);
    }
    getch();
    return 0;
}

