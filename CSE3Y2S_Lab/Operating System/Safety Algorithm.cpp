#include<bits/stdc++.h>
using namespace std;

int P, R;
bool isSafe(int avail[], int maxm[][], int allot[][], int need[][])
{
    bool finish[P] = {0};
    int safeSeq[P], work[R];
    for (int i = 0; i < R ; i++)
        work[i] = avail[i];

    int cnt = 0;
    while (cnt < P)
    {
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R)
                {
                    for (int k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];
                    safeSeq[cnt++] = p;
                    finish[p] = 1;

                    found = true;
                }
            }
        }

        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }

    cout << "System is in safe state.\nSafe"
         " sequence is: ";
    for (int i = 0; i < P ; i++)
        cout << safeSeq[i] << " ";

    return true;
}

int main()
{
    //freopen("Bankers.txt","r",stdin);
    printf("Number of processes: ");
    scanf("%d",&P);

    printf("Number of resources: ");
    scanf("%d",&R);

    int alloc[P][R], mx[P][R], avail[R], instance[R];
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

    int need[P][R];
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
            need[i][j] = mx[i][j] - alloc[i][j];
    }

    //if(isSafe(avail, mx, alloc, need));
    return 0;
}
