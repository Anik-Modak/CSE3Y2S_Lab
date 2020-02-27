#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(nullptr);
using namespace std;

int btime[200];
struct process
{
    int pid,bstime,orbt;
    process() {}
    process(int pi,int bt)
    {
        pid=pi;
        orbt=bstime=bt;
    }
    bool operator < (const process&x)
    {
        return bstime < x.bstime;
    }
} plist[200];

int main()
{
    int i,j,a,b,ts,cn=0,x,n,wtime=0,curtime=0,ftime=0,stm=0,tslice,ty;
    double avgwt=0,avgft=0;
    queue<process> q;
    queue<process> q2;

    process pf;
    //freopen("testrr.txt","r",stdin);
    scanf("%d %d",&n,&tslice);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d",&x,&ty);
        if(ty==1)
            q.push(process(i,x));
        else
        {
            q2.push(process(i,x));
        }

    }
    while(!q.empty())
    {
        pf=q.front();
        q.pop();
        if(pf.bstime<=tslice)
        {
            stm=curtime;
            curtime+=pf.bstime;
            wtime+=curtime-pf.orbt;
            ftime+=curtime;

        }
        else
        {
            stm=curtime;
            curtime+=tslice;
            pf.bstime-=tslice;
            q.push(pf);

        }
        printf("PID: %d Starting: %d, Finishing: %d\n",pf.pid,stm,curtime);
    }
    while(!q2.empty())
    {
        pf=q2.front();
        q2.pop();
        wtime+=curtime;
        stm=curtime;
        curtime+=pf.bstime;
        ftime+=curtime;
        //curtime++;
        printf("PID: %d Starting: %d, Finishing: %d\n",pf.pid,stm,curtime);
    }


    avgwt=(double)wtime/n;
    avgft=(double)ftime/n;

    printf("Average waiting time: %.2lf\n",avgwt);
    printf("Average Finishing time: %.2lf\n",avgft);

    return 0;
}
