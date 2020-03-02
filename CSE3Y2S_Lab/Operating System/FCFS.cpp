#include<bits/stdc++.h>
using namespace std;

void findAverageTime(int n, int bt[])
{
    int wt[n], tat[n], t_wt = 0, t_tat = 0;
    wt[0] = 0;
    tat[0] = bt[0];
    for(int i=1; i<n; i++)
    {
        wt[i] = bt[i-1] + wt[i-1];
        tat[i] = bt[i] + wt[i];
    }

    cout << "\nProcesses  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        t_wt = t_wt + wt[i];
        t_tat = t_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] << "\n";
    }
    cout << "\nAverage waiting time = "<< t_wt/(double)n<<"\n";
    cout << "\nAverage turn around time = "<< t_tat/(double)n<<"\n";
}

int main()
{
    //freopen("fcfs.txt","r",stdin);
    int n; //3
    cout<<"Enter Total Process: ";
    cin>>n;

    int bt[n], wt = 0; //24 3 3
    cout<<"Enter BURST Time: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process P["<<i+1<<"] : ";
        cin>>bt[i];
    }
    findAverageTime(n,  bt);
    return 0;
}


