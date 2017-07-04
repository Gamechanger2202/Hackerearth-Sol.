#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n,m,k,i,live[1000001],dist[1000001],a[1000001],b[1000001];
vector <int> g[1000001];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        g[a[i]].push_back(i);
        g[b[i]].push_back(i);
        live[i]=1000000000;
    }
    for(i=0;i<k;i++)
    {
        int c,d;
        scanf("%d%d",&c,&d);

        d--;
        live[d]=c;
    }
    for(i=0;i<=n;i++)
        dist[i]=1000000000;
    queue <int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(i=0;i<g[x].size();i++)
        {
            int edge=g[x][i];
            if(live[edge]<=dist[x])
                continue;
            int to;
            if(a[edge]==x)
                to=b[edge];
            else
                to=a[edge];
            if(dist[to]>dist[x]+1)
            {
                dist[to]=dist[x]+1;
                q.push(to);
            }
        }
    }
    if(dist[n]>=1000000)
        dist[n]=-1;
    printf("%d\n",dist[n]);
    return 0;
}
