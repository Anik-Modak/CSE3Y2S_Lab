#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid; // Process ID
    int bt; // Burst Time
    int pr; // Priority
};

bool cmp(Process a, Process b)
{
    return a.pr < b.pr;
}

void findAverageTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    wt[0] = 0;
    tat[0] = proc[0].bt;
    for(int i=1; i<n; i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1];
        tat[i] = proc[i].bt + wt[i];
    }

    cout << "\nProcesses  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t" << proc[i].bt <<"\t    "<< wt[i] <<"\t\t  " << tat[i] << "\n";
    }

    cout << "\nAverage waiting time = "<< total_wt/(double)n<<"\n";
    cout << "\nAverage turn around time = "<< total_tat/(double)n<<"\n";
}

int main()
{
    //freopen("Priority.txt","r",stdin);
    int n;
    cout<<"Enter Total Processes: ";
    cin>>n;

    Process proc[n];
    cout<<"\nEnter burst time and Priority:\n";
    for(int i=0; i<n; i++)
    {
        cin>>proc[i].bt>>proc[i].pr;
        proc[i].pid = i+1;
    }

    sort(proc, proc+n, cmp);
    findAverageTime(proc, n);
    return 0;
}
/*input:
5
10  3
1	1
2	4
1	5
5	2
outpu: 8.2 12*/
