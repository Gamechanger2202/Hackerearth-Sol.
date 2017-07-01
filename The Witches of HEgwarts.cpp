#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define f(n) for(int i=0;i<n;i++)
#define ff(n) for(int j=0;j<n;j++)
#define pb(x) push_back(x)
#define mp make_pair
#define ll long long
#define mod 1000000007
using namespace std;
map <ll int,ll int> dp,vis;
int solve(ll int t)
{
    queue <int> q;
    q.push(t);
    dp[t]=0;
    vis[t]++;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        if(n==1)
            return dp[1];
        if(vis[n-1]==0)
        {
            vis[n-1]++;
            q.push(n-1);
            dp[n-1]=dp[n]+1;
        }
        if(vis[(n/2)]==0 && n%2==0)
        {
            vis[n/2]++;
            q.push(n/2);
            dp[n/2]=dp[n]+1;
        }
        if(vis[n/3]==0 && n%3==0)
        {
            vis[n/3]++;
            q.push(n/3);
            dp[n/3]=dp[n]+1;
        }
    }
}
int main()
{
    ll int t,n;
    cin>>t;
    while(t--)
    {
        dp.clear();
        vis.clear();
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
