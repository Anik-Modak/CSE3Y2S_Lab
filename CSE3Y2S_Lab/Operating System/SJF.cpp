//Anik_Modak
#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<pii> bt;
void findWaitingTime(int n, int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  bt[i-1].first + wt[i-1];
    }
}

void findTurnAroundTime(int n, int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i].first + wt[i];
    }
}

void findAverageTime(int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(n, wt);
    findTurnAroundTime(n, wt, tat);

    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << (bt[i].second + 1) << "\t\t" << bt[i].first <<"\t    "<< wt[i] <<"\t\t  " << tat[i] << "\n";
    }

    cout << "\nAverage waiting time = "<< total_wt/(float)n<<"\n";
    cout << "\nAverage turn around time = "<< total_tat/(float)n<<"\n";
}

int main()
{
    int n;
    cout<<"Enter Total Process: ";
    cin>>n;

    int burst;
    cout<<"Enter BURST Time: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process: P"<<i+1<<": ";
        cin>>burst;
        bt.push_back({burst, i});
    }
    sort(bt.begin(), bt.end());
    findAverageTime(n);
    return 0;
}
