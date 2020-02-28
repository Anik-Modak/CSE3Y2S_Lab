#include<bits/stdc++.h>
using namespace std;

void findWaitingTime(int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  bt[i-1] + wt[i-1];
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(n, bt, wt);
    findTurnAroundTime(n, bt, wt, tat);

    cout << "\nProcesses  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] << "\n";
    }

    cout << "\nAverage waiting time = "<< total_wt/(float)n<<"\n";
    cout << "\nAverage turn around time = "<< total_tat/(float)n<<"\n";
}

int main()
{
    //freopen("fcfs.txt","r",stdin);
    int n;
    cout<<"Enter Total Process: ";
    cin>>n;

    int bt[n], wt = 0;
    cout<<"Enter BURST Time: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process P["<<i+1<<"] : ";
        cin>>bt[i];
    }
    findAverageTime(n,  bt);
    return 0;
}

