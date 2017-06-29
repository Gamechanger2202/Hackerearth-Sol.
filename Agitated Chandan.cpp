#include<bits/stdc++.h>
#define f(n) for(i=0;i<n;i++)
#define pb(x) push_back(x)
#define mp make_pair
using namespace std;
long long int t,i,n,x,y,z,a,b,c,m,level[100005],vis[100005],w;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        queue<int> q;
        vector <pair<long long int,long long int> > v[100005];
        for(i=0;i<(n-1);i++)
        {
            cin>>a>>b>>c;
            v[a].pb(mp(b,c));
            v[b].pb(mp(a,c));
        }
        memset(vis,0,sizeof(vis));
        memset(level,0,sizeof(level));
        q.push(1);
        m=0;
        while(!q.empty())
        {
            x=q.front();
            q.pop();
            vis[x]=1;
            for(i=0;i<v[x].size();i++)
            {
                y=v[x][i].first;
                w=v[x][i].second;
                if(!vis[y])
                {
                    q.push(y);
                    vis[y]=1;
                    level[y]=level[x]+w;
                    if(m<level[y])
                    {
                        m=level[y];
                        z=y;
                    }
                }
            }
        }
        memset(vis,0,sizeof(vis));
        memset(level,0,sizeof(level));
        m=0;
        q.push(z);
        while(!q.empty())
        {
            x=q.front();
            q.pop();
            vis[x]=1;
            for(i=0;i<v[x].size();i++)
            {
                y=v[x][i].first;
                w=v[x][i].second;
                if(!vis[y])
                {
                    q.push(y);
                    vis[y]=1;
                    level[y]=level[x]+w;
                    if(m<level[y])
                    {
                        m=level[y];
                    }
                }
            }
        }
        int ans;
        if(m<100)
        ans=0;
        else
        if(m>10000)
        ans=10000;
        else
        if(m>1000)
        ans=1000;
        else
        ans=100;
        cout<<ans<<" "<<m<<endl;
    }
    return 0;
}
