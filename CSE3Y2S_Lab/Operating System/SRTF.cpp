#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
};

void findWaitingTime(Process proc[], int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int st = 0, f_time;
    bool check = false;

    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                st = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }
        rt[st]--;
        minm = rt[st];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[st] == 0)
        {
            complete++;
            check = false;
            f_time = t + 1;
            wt[st] = f_time -proc[st].bt - proc[st].art;
            if (wt[st] < 0)
                wt[st] = 0;
        }
        t++;
    }
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    cout << "Processes "<< " Burst time "<< " Waiting time "<< " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t " << wt[i]<< "\t\t " << tat[i] << endl;
    }
    cout <<"\nAverage waiting time = "<< total_wt/(float)n<<"\n";
    cout <<"\nAverage turn around time = "<< total_tat/(float)n<<"\n";
}

int main()
{
    //freopen("SRTF.txt","r",stdin);
    int n;
    cout<<"Enter Total Processes: ";
    cin>>n;

    Process proc[n];
    cout<<"\nEnter process id, burst time and arriving time\n";
    for(int i=0; i<n; i++)
        cin>>proc[i].pid>>proc[i].bt>>proc[i].art;

    findavgTime(proc, n);
    return 0;
}
