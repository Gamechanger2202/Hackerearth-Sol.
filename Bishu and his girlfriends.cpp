#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define f(n) for(int i=0;i<n;i++)
#define ff(n) for(int j=0;j<n;j++)
#define pb(x) push_back(x)
#define mp make_pair
#define ll long long
#define mod 1000000007
using namespace std;
vector <int> v[1001];
int main()
{
    int n,a,b,qq,ele,level[1001],vis[1001];
    cin>>n;
    while(--n)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    memset(level,0,sizeof(level));
    memset(vis,0,sizeof(vis));
    queue <int> q;
    q.push(1);
    vis[1]++;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        f(v[x].size())
        {
            if(!vis[v[x][i]])
            {
                q.push(v[x][i]);
                level[v[x][i]]=level[x]+1;
                vis[v[x][i]]++;
            }
        }
    }
    int j=INT_MAX,f=INT_MAX;
    cin>>qq;
    while(qq--)
    {
        cin>>ele;
        if(j==level[ele])
        {
            if(ele<f)
                f=ele;
        }
        else if(j>level[ele])
        {
            j=level[ele];
            f=ele;
        }
       // cout<<j<<"   "<<f<<endl;
    }
    cout<<f;
    return 0;
}
