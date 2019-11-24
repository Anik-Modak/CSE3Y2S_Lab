#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Total Number of Process:";
    cin>>n;

    int bt[n], p[n], wt[n], tat[n], pr[n];
    cout<<"\nEnter Burst Time and Priority:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process P["<<i+1<<"]: ";
        cin>>bt[i]>>pr[i];
        p[i]=i+1;
    }

    double total = 0, avg_wt, avg_tat;
    for(int i=0; i<n; i++)
    {
        int pos = i;
        for(int j=i+1; j<n; j++)
        {
            if(pr[j] < pr[pos])
                pos = j;
        }

        int temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;
    for(int i=1; i<n; i++)
    {
        wt[i]=0;
        for(int j=0; j<i; j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt = total/n;
    total = 0;

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(int i=0; i<n; i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }

    avg_tat=total/n;
    cout<<"\n\nAverage Waiting Time = "<<avg_wt<<endl;
    cout<<"Average Turnaround Time = "<<avg_tat<<endl;

    return 0;
}
