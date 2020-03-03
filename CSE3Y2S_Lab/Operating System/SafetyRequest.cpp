#include<bits/stdc++.h>
#define MX 105
using namespace std;

int alloc[MX][MX], mx[MX][MX], need[MX][MX];
int safeSeq[MX], work[MX], avail[MX], request[MX];

void calculateNeed(int P, int R)
{
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
            need[i][j] = mx[i][j] - alloc[i][j];
    }
}

bool isValid(int pi, int R)
{
    for(int i=0; i<R; i++)
    {
        if(need[pi][i] > work[i])
            return false;
    }
    return true;
}

bool isSafety(int P, int R)
{
    bool finish[P] = {0};
    for (int i = 0; i < R ; i++)
        work[i] = avail[i];

    int cnt = 0;
    while(cnt < P)
    {
        bool found = false;
        for(int i = 0; i < P; i++)
        {
            if(finish[i] == 0 && isValid(i, R))
            {
                for(int j = 0 ; j < R ; j++)
                    work[j] += alloc[i][j];

                safeSeq[cnt++] = i;
                finish[i] = 1;
                found = true;
            }
        }
        if (found == false)
            return 0;
    }
    return 1;
}

bool resourceRequest(int pid, int p, int r)
{
    for(int i=0; i<r; i++)
    {
        avail[i] = avail[i] - request[i];
        alloc[pid][i] = alloc[pid][i] + request[i];
        need[pid][i] = need[pid][i] - request[i];
    }

    if(isSafety(p, r))
        return true;
    else
    {
        for(int i=0; i<r; i++)
        {
            avail[i] = avail[i] + request[i];
            alloc[pid][i] = alloc[pid][i] - request[i];
            need[pid][i] = need[pid][i] + request[i];
        }
        return false;
    }
}

int main()
{
    //freopen("safety.txt","r",stdin);
    int P, R;
    printf("Number of processes: ");
    scanf("%d",&P);

    printf("Number of resources: ");
    scanf("%d",&R);

    int instance[R];
    for(int i=0; i<R; i++)
    {
        printf("Number of instance in resource %c: ",i+65);
        scanf("%d",&instance[i]);
    }

    printf("Allocation Matrix:\n");
    for(int i=0; i<P; i++)
        for(int j=0; j<R; j++)
            scanf("%d",&alloc[i][j]);

    printf("MAX Matrix:\n");
    for(int i=0; i<P; i++)
        for(int j=0; j<R; j++)
            scanf("%d",&mx[i][j]);

    for(int i=0; i<R; i++)
    {
        int sum = 0;
        for(int j=0; j<P; j++)
            sum += alloc[j][i];
        avail[i] = instance[i] - sum;
    }
    calculateNeed(P, R);

    if(isSafety(P, R))
    {
        cout << "\nSystem is in safe state.\n";
        while(1)
        {
            int cmd;
            cout<<"Press 1 to request resource, Press 0 to Exit : "<<endl;
            cin>>cmd;

            if(cmd)
            {
                int pid;
                cout<<"Enter process id : ";
                cin>>pid;

                cout<<"Enter requested resources for process p["<<pid<<"] : ";
                for(int i=0; i<R; i++)
                    cin>>request[i];

                bool valid = true;
                for(int i=0; i<R; i++)
                {
                    if(request[i] > need[pid][i])
                    {
                        cout<<"Requested resources can not be greater than needed resources.\n";
                        valid = false;
                        break;
                    }
                }

                if(valid == false)
                    continue;

                for(int i=0; i<R; i++)
                {
                    if(request[i]>avail[i])
                    {
                        cout<<"Not Enough Resources. P["<<pid<<"] must wait.\n";
                        valid = false;
                        break;
                    }
                }

                if(valid == false)
                    continue;

                if(resourceRequest(pid, P, R))
                {
                    cout<<"The Resources has been allocated.\n";
                    cout << "\nSystem is in safe state.\nSafe sequence is: ";
                    for (int i = 0; i < P ; i++)
                        cout << safeSeq[i] << " ";
                    cout<<endl;
                }
                else
                    cout<<"Request Can't be granted because the system will be in an unsafe state.\n";
            }
            else
                return 0;
        }
    }
    else
        cout << "System is not in safe state\n";
    return 0;
}


