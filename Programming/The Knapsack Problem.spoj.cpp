//Anik_Modak
#include<bits/stdc++.h>
#define MX 2005
using namespace std;

int we[MX], cost[MX];
int dp[MX][MX], n, CAP;
int solve(int i, int sum)
{
    if(i==n)
        return 0;

    if(dp[i][sum] != -1)
        return dp[i][sum];

    int p1, p2;
    if(sum + we[i] <= CAP)
        p1 = cost[i] + solve(i + 1, sum + we[i]);
    else
      p1 = 0;
    p2 = solve(i+1, sum);

    return dp[i][sum] = max(p1, p2);
}

int main()
{
    cin>>CAP>>n;
    for(int i=0; i<n; i++)
        cin>>we[i]>>cost[i];

    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0);
    cout<<ans<<"\n";
    return 0;
}
