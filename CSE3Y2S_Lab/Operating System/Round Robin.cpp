#include<bits/stdc++.h>

int main()
{
    int n, remain;
    printf("Enter Total Process: ");
    scanf("%d",&n);
    remain = n;

    int bt[n], rt[n];
    printf("\nEnter Burst Time:\n");
    for(int cnt=0; cnt<n; cnt++)
    {
        printf("Process P[%d]: ",cnt+1);
        scanf("%d",&bt[cnt]);
        rt[cnt] = bt[cnt];
    }

    int flag=0, time_quantum;
    printf("\nEnter Time Quantum: ");
    scanf("%d",&time_quantum);
    printf("\nProcess\t|TurnaroundTime\t|Waiting Time\n");

    int time = 0, cnt = 0, wait_time = 0, tur_time = 0;
    while(remain)
    {
        if(rt[cnt]<=time_quantum && rt[cnt]>0)
        {
            time += rt[cnt];
            rt[cnt]=0;
            flag=1;
        }
        else if(rt[cnt]>0)
        {
            rt[cnt]-=time_quantum;
            time+=time_quantum;
        }

        if(rt[cnt]==0 && flag==1)
        {
            printf("P[%d]\t|\t%d\t|\t%d\n",cnt+1,time,time-bt[cnt]);
            wait_time += time-bt[cnt];
            tur_time += time;
            flag=0;
            remain--;
        }

        if(cnt==n-1)
            cnt=0;
        else
            cnt++;
    }

    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
    printf("Average Turnaround Time = %f\n",tur_time*1.0/n);
    return 0;
}
