#include<bits/stdc++.h>
#define MX 105
using namespace std;

int p[MX], b[MX], wt[MX], tTime[MX];
double avgwt, avgtTime;

void findWt(int n)
{
    int s = 0;
    for(int i =0; i<n; i++)
    {
        if(i==0)
            wt[i]=0;
        else
        {
            wt[i]=b[i-1]+wt[i-1];
        }
        s+= wt[i];
    }
    avgwt = s*1.0/n;
}

void tournAroundTime(int n)
{
    int s = 0;
    for(int i = 0; i<n; i++)
    {
        tTime[i] = wt[i]+b[i];
        s+= tTime[i];
    }
    avgtTime = s*1.0/n;
}

int main()
{
    int n;
    cout<<"Enter numbers of process: ";
    cin>>n;

    int index[n+3];
    cout<<"Enter BURST Time: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process: P"<<i+1<<": ";
        cin>>b[i];
        index[b[i]] = i+1;
    }

    sort(b, b+n);
    findWt(n);
    tournAroundTime(n);

    cout << "\nProcesses "<< " Burst time "<< " Waiting time " << " Turn around time\n";
    for (int i=0; i<n; i++)
    {
        cout << " " << index[b[i]] << "\t\t" << b[i] <<"\t "
             << wt[i] <<"\t\t " << tTime[i] <<endl;
    }
    cout << "Average waiting time = " <<avgwt<<endl;
    cout << "\nAverage turn around time = "<<avgtTime<<endl;
    return 0;
}
