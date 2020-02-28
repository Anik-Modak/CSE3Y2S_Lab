#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, i, j, k, l=0, e, r;
    cout<<"Enter Number of Processes: ";
    cin>>n;
    cout<<"Enter Number of Resources: ";
    cin>>m;
    int Allocation[n][m], Need[n][m], Max[n][m];
    int Available[m], Finish[n], Work[m], Sequence[n];
    bool Flag, Unsafe = false;

    cout<<"Enter Total Number of Instances: "<<endl;
    for(i=0; i<m; i++)
    {
        //cout<<"R["<<i<<"]: ";
        cin>>Available[i];
    }
    cout<<"Enter Maximum Needs of Processes: ";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            //cout<<"P["<<i<<"]->R["<<j<<"]: ";
            cin>>Max[i][j];
        }
    }
    cout<<"Enter Allocation of Processes: ";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            //cout<<"P["<<i<<"]->R["<<j<<"]: ";
            cin>>Allocation[i][j];
            Need[i][j] = Max[i][j] - Allocation[i][j];
            Available[j] = Available[j] - Allocation[i][j];
            Work[j] = Available[j];
        }
        Finish[i] = 0;
    }
    cout<<endl;

Safety:
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            Flag = true;
            for(k=0; k<m; k++)
            {
                if(!(Finish[j]==0 && Need[j][k]<=Work[k]))
                    Flag = false;
            }
            if(Flag==true)
            {
                Finish[j]=1;
                for(k=0; k<m; k++)
                {
                    Work[k] = Work[k] + Allocation[j][k];
                }
                Sequence[l] = j;
                l++;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        if(Finish[i]==0)
            Unsafe = true;
    }
    if(Unsafe==true)
    {
        cout<<"There is a Unsafe State in The System."<<endl;
    }
    else
    {
        cout<<"The System is in Safe State."<<endl;
        cout<<"Sequence: ";
        for(i=0; i<n; i++)
        {
            cout<<"P["<<Sequence[i]<<"] ";
        }
    }
    cout<<endl<<"Press 1 to Make a Request, Press 0 to End: ";
    cin>>e;
    if(e==1)
    {
        cout<<"Request for Process No (0-"<<n-1<<"): ";
        cin>>r;
        for(j=0; j<m; j++)
        {
            Available[j] = Available[j] + Allocation[r][j];
            Work[j] = Available[j];
        }
        Unsafe = false;
        l = 0;
        cout<<"Enter Instances of Resources Allocated for P["<<r<<"]: ";
        for(j=0; j<m; j++)
        {
            cin>>Allocation[r][j];
            Need[r][j] = Max[r][j] - Allocation[r][j];
            Available[j] = Available[j] - Allocation[r][j];
            Work[j] = Available[j];
        }
        for(i=0; i<n; i++)
        {
            Finish[i] = 0;
        }
        goto Safety;
    }
    else
        return 0;
}
