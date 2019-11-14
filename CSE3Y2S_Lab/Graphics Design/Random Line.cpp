//Anik_Modak
#include<Windows.h>
#define MX 100000
#include<graphics.h>
#include<time.h>
#include <unistd.h>

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    for(int t=1; t<=50; t++)
    {
        setcolor(GREEN);
        line(rand()%450,rand()%450,rand()%450,rand()%450);
        usleep(MX);
        cleardevice();

        setcolor(RED);
        line(rand()%350,rand()%350,rand()%350,rand()%350);
        usleep(MX);
        cleardevice();

        setcolor(BLUE);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        usleep(MX);
        cleardevice();

        setcolor(YELLOW);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        usleep(MX);
        cleardevice();

        setcolor(GREEN);
        line(rand()%450,rand()%450,rand()%450,rand()%450);
        setcolor(RED);
        line(rand()%350,rand()%350,rand()%350,rand()%350);
        setcolor(BLUE);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        usleep(MX);
        setcolor(YELLOW);
        line(rand()%450,rand()%350,rand()%450,rand()%350);
        usleep(MX);
        cleardevice();
    }
    getch();
    closegraph();
    return 0;
}

