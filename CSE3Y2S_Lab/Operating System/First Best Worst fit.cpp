#include <bits/stdc++.h>
#define MX 105
using namespace std;

int hSize[MX];
int pSize[MX];
int allocation[MX];
int tmpSize[MX];

void PrintOutput(int p)
{
    cout<<"Process ID\tProcess Size\tHole No\tHole Size\n";
    for(int i=0; i<p; i++)
    {
        if(allocation[i] == -1)
            cout<<i+1<<"\t\t"<<pSize[i]<<"\t\tNot Allocated\n";
        else
            cout<<i+1<<"\t\t"<<pSize[i]<<"\t\t"<<allocation[i]+1<<"\t\t"<<hSize[allocation[i]]<<"\n";
    }
    return;
}

void FirstFit(int p, int h)
{
    for(int i=0; i<p; i++)
    {
        allocation[i] = -1;
        for(int j=0; j<h; j++)
        {
            if(pSize[i] <= tmpSize[j])
            {
                tmpSize[j] -= pSize[i];
                allocation[i] = j;
                break;
            }
        }
    }
    cout<<"\nFirst Fit Allocation : \n";
    PrintOutput(p);
    return;
}

void BestFit(int p, int h)
{
    for(int i=0; i<p; i++)
    {
        allocation[i] = -1;
        int minSpace = 10000;
        int holeIndex = -1;
        for(int j=0; j<h; j++)
        {
            if(pSize[i] <= tmpSize[j] && tmpSize[j] < minSpace)
            {
                minSpace = tmpSize[j];
                holeIndex = j;
            }
        }
        if(holeIndex == -1)
            continue;

        allocation[i] = holeIndex;
        tmpSize[holeIndex] -= pSize[i];
    }
    cout<<"\nBest Fit Allocation : \n";
    PrintOutput(p);
    return;
}

void WorstFit(int p, int h)
{
    for(int i=0; i<p; i++)
    {
        allocation[i] = -1;
        int maxSpace = -1;
        int holeIndex = -1;
        for(int j=0; j<h; j++)
        {
            if(pSize[i] <= tmpSize[j] && tmpSize[j] > maxSpace)
            {
                maxSpace = tmpSize[j];
                holeIndex = j;
            }
        }
        if(holeIndex == -1)
            continue;

        allocation[i] = holeIndex;
        tmpSize[holeIndex] -= pSize[i];
    }
    cout<<"\nWorst Fit Allocation : \n";
    PrintOutput(p);
    return;
}

int main()
{
    int h;
    cout<<"Enter total number of holes : ";
    cin>>h;
    cout<<"Enter size of each hole : ";
    for(int i=0; i<h; i++)
        cin>>hSize[i];

    int p;
    cout<<"Enter total number of processes : ";
    cin>>p;
    cout<<"Enter size of each process : ";
    for(int i=0; i<p; i++)
        cin>>pSize[i];

    copy(hSize, hSize+h, tmpSize);
    FirstFit();
    copy(hSize, hSize+h, tmpSize);
    BestFit();
    copy(hSize, hSize+h, tmpSize);
    WorstFit();
    return 0;
}
