#include<bits/stdc++.h>
using namespace std;

void findAverageTime(int n, int rt[], int bt[], int tq)
{
    int remain = n, time = 0, i = 0;
    cout<<"\nProcesses  "<<" Burst time  "<<" Waiting time "<<" Turn around time\n";

    double wt = 0, tat = 0;
    while(remain)
    {
        if(rt[i]<=tq && rt[i]>0)
        {
            time += rt[i];
            rt[i] = 0;
        }
        else if(rt[i] > 0)
        {
            rt[i]-=tq;
            time+=tq;
        }

        if(rt[i]==0)
        {
            cout<<"   "<<(i+1)<<"\t\t"<<bt[i]<<"\t    "<<time-bt[i]<<"\t\t  "<<time<<"\n";
            wt += time-bt[i];
            tat += time;
            remain--;
            rt[i] = -1;
        }

        if(i==n-1)
            i=0;
        else
            i++;
    }
    cout<<"\nAverage waiting time = "<<wt/n<<"\n";
    cout<<"\nAverage turn around time = "<<tat/n<<"\n";
}

int main()
{
    freopen("round.txt","r",stdin);
    int n; //3
    cout<<"Enter Total Process: ";
    cin>>n;

    int bt[n], rt[n], tq;
    cout<<"\nEnter Burst Time:\n"; //24 3 3
    for(int i=0; i<n; i++)
    {
        cout<<"Process P["<<i+1<<"]: ";
        cin>>bt[i];
        rt[i] = bt[i];
    }
    cout<<"\nEnter Time Quantum: "; // 4
    scanf("%d",&tq);

    findAverageTime(n, rt, bt, tq); //5.667 15.667
    return 0;
}
