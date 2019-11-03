//Anik_Modak
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout<<"Enter numbers of process: ";
    cin>>n;

    int bt[n], wt = 0;
    cout<<"Enter BURST Time: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process: P"<<i+1<<": ";
        cin>>bt[i];
    }

    double avg, sum = 0;
    sort(bt, bt+n);

    cout<<"Waiting Time: ("<<wt;
    for(int i=0; i<n-1; i++)
    {
        wt = (wt + bt[i]);
        sum += wt;
        cout<<"+" << wt;
    }
    cout<<") = "<<sum<<"\n";

    avg = sum/n;
    cout<<"Average Time: "<<avg<<"\n";
    return 0;
}
