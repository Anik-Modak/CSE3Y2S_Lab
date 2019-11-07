//Anik_Modak
#include<bits/stdc++.h>
#define MX 1005
using namespace std;

int we[MX], cost[MX];
int dp[MX][MX], n, CAP;
int solve(int i, int sum)
{
    if(i >= n)
        return 0;

    if(dp[i][sum] != -1)
        return dp[i][sum];

    int p1, p2;
    if(sum + cost[i] <= CAP)
        p1 = cost[i] + solve(i + 2, sum + cost[i]);
    else
        p1 = 0;
    p2 = solve(i+1, sum);
    return dp[i][sum] = max(p1, p2);
}

int main()
{
    ios::sync_with_stdio(false);
    int t, cas = 0;
    cin>>t;

    while(t--)
    {
        cin>>n>>CAP;
        for(int i=0; i<n; i++)
            cin>>cost[i];

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0);
        cout<<"Scenario #"<< ++cas <<": "<<ans<<"\n";
    }
    return 0;
}

