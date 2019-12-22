// Banker's Algorithm
#include<bits/stdc++.h>

int main()
{
    //freopen("Bankers.txt","r",stdin);
    int n, m;
    printf("Number of processes: ");
    scanf("%d",&n);

    printf("Number of resources: ");
    scanf("%d",&m);

    int alloc[n][m], mx[n][m], avail[m], instance[m];
    for(int i=0; i<m; i++)
    {
        printf("Number of instance in resource %c: ",i+65);
        scanf("%d",&instance[i]);
    }

    printf("Allocation Matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&alloc[i][j]);

    printf("MAX Matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&mx[i][j]);

    for(int i=0; i<m; i++)
    {
        int sum = 0;
        for(int j=0; j<n; j++)
            sum += alloc[j][i];
        avail[i] = instance[i] - sum;
    }

    int need[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            need[i][j] = mx[i][j] - alloc[i][j];
    }

    int f[n], ans[n], ind = 0;
    memset(f, false, sizeof(f));

    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("Following is the SAFE Sequence\n");
    for (int i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);

    return 0;
}
