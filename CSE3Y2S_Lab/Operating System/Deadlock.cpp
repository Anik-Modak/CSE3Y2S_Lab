#include<stdio.h>

int main()
{
    int i, j, np, nr;
    printf("Enter the no of process: ");
    scanf("%d",&np);
    printf("Enter the no of resources: ");
    scanf("%d",&nr);

    int alloc[np][nr],request[np][nr],avail[nr],r[nr],w[nr];
    for(i=0; i<nr; i++)
    {
        printf("Total Amount of the Resource R%d: ",i+1);
        scanf("%d",&r[i]);
    }

    printf("\nEnter the request matrix:");
    for(i=0; i<np; i++)
        for(j=0; j<nr; j++)
            scanf("%d",&request[i][j]);

    printf("\nEnter the allocation matrix:");
    for(i=0; i<np; i++)
        for(j=0; j<nr; j++)
            scanf("%d",&alloc[i][j]);

    for(j=0; j<nr; j++)
    {
        avail[j]=r[j];
        for(i=0; i<np; i++)
            avail[j] -= alloc[i][j];
    }

    bool mark[np+3] = {0};
    for(i=0; i<np; i++)
    {
        int cnt=0;
        for(j=0; j<nr; j++)
        {
            if(alloc[i][j]==0)
                cnt++;
            else
                break;
        }
        if(cnt==nr)
            mark[i]=1;
    }

    for(j=0; j<nr; j++)
        w[j] = avail[j];

    for(i=0; i<np; i++)
    {
        int flag=0;
        if(mark[i]!=1)
        {
            for(j=0; j<nr; j++)
            {
                if(request[i][j]<=w[j])
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                mark[i]=1;
                for(j=0; j<nr; j++)
                    w[j]+=alloc[i][j];
            }
        }
    }
    //checking for unmarked processes
    int deadlock=0;
    for(i=0; i<np; i++)
        if(mark[i]!=1)
            deadlock=1;

    if(deadlock)
        printf("\n Deadlock detected");
    else
        printf("\n No Deadlock possible");
}
