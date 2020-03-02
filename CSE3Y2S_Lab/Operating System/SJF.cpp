//Anik_Modak
#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<pii> bt;
void findAverageTime(int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    wt[0] = 0;
    tat[0] = bt[0].first;
    for(int i=1; i<n; i++)
    {
        wt[i] = bt[i-1].first + wt[i-1];
        tat[i] = bt[i].first + wt[i];
    }

    cout<<"\nProcesses  "<<" Burst time  "<<" Waiting time "<<" Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout<<"   "<<(bt[i].second + 1)<<"\t\t"<<bt[i].first <<"\t    "<<wt[i]<<"\t\t  "<<tat[i]<<"\n";
    }

    cout<<"\nAverage waiting time = "<<total_wt/(double)n<<"\n";
    cout<<"\nAverage turn around time = "<<total_tat/(double)n<<"\n";
}

int main()
{
    //freopen("sjf.txt","r",stdin);
    int n; //4
    cout<<"Enter Total Process: ";
    cin>>n;

    int burst; //6 8 7 3
    cout<<"Enter BURST Time: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process: P"<<i+1<<": ";
        cin>>burst;
        bt.push_back({burst, i});
    }
    sort(bt.begin(), bt.end());
    findAverageTime(n); //7 13
    return 0;
}
