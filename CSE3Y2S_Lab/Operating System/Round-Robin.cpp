#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, remain;
    cout<<"Enter Total Process: ";
    cin>>n;
    remain = n;

    int bt[n], rt[n];
    cout<<"\nEnter Burst Time:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process P["<<i+1<<"]: ";
        cin>>bt[i];
        rt[i] = bt[i];
    }

    int flag=0, time_quantum;
    cout<<"\nEnter Time Quantum: ";
    scanf("%d",&time_quantum);
    cout<<"\nProcess \tWaiting Time \tTurnaround Time";

    int time = 0, i = 0;
    double wait_time = 0, tur_time = 0;
    while(remain)
    {
        if(rt[i]<=time_quantum && rt[i]>0)
        {
            time += rt[i];
            rt[i]=0;
            flag=1;
        }
        else if(rt[i]>0)
        {
            rt[i]-=time_quantum;
            time+=time_quantum;
        }

        if(rt[i]==0 && flag==1)
        {
            cout<<"\n"<<i+1<<"\t\t"<<time<<"\t\t"<<time-bt[i];
            wait_time += time-bt[i];
            tur_time += time;
            flag=0;
            remain--;
        }

        if(i==n-1)
            i=0;
        else
            i++;
    }

    cout<<"\n\nAverage Waiting Time = "<<wait_time/n;
    cout<<"\nAverage Turnaround Time = "<<tur_time/n<<"\n";
    return 0;
}
