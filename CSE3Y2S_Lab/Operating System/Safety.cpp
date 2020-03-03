#include<bits/stdc++.h>
#define MX 105
using namespace std;

int alloc[MX][MX], mx[MX][MX], need[MX][MX];
int safeSeq[MX], work[MX], avail[MX];

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
        //printf("Number of instance in resource %c: ",i+65);
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
        cout << "\nSystem is in safe state.\nSafe sequence is: ";
        for (int i = 0; i < P ; i++)
            cout << safeSeq[i] << " ";
        cout<<endl;
    }
    else
        cout << "System is not in safe state\n";
    return 0;
}

