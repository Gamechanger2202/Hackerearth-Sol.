#include<bits/stdc++.h>
#define f(n) for(int i=0;i<n;i++)
#define ff(n) for(int j=0;j<n;j++)
#define pb(x) push_back(x)
#define mp make_pair
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    int n,m,x,y;
    vector <int> v[1001];
    cin>>n>>m;
    f(m)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    queue <int> q;
    q.push(0);
    int level[1001],vis[1001];
    memset(level,0,sizeof(level));
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        f(v[x].size())
        {
            if(vis[v[x][i]]==false)
            {
                level[v[x][i]]=level[x]+1;
                vis[v[x][i]]=true;
                q.push(v[x][i]);
            }
        }
    }
    for(int i=1;i<n;i++)
        cout<<level[i]<<endl;
    return 0;
}
