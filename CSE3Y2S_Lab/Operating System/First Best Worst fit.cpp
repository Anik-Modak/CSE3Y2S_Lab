#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of Holes: ";
    cin>>n;

    int Hole[n], Process;
    cout<<"Enter Size of Holes: ";
    for(int i=0; i<n; i++)
        cin>>Hole[i];

    cout<<"Enter Process Size: ";
    cin>>Process;

    for(int i=0; i<n; i++)
    {
        if(Process <= Hole[i])
        {
            cout<<"\nFirst Fit Hole is of Size: "<<Hole[i]<<endl;
            break;
        }
    }

    sort(Hole, Hole+n);
    for(int i=0; i<n; i++)
    {
        if(Process <= Hole[i])
        {
            cout<<"Best Fit Hole is of Size: "<<Hole[i]<<endl;
            break;
        }
    }
    cout<<"Worst Fit Hole is of Size: "<<Hole[n-1]<<endl;
    return 0;
}
