#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define f(n) for(int i=0;i<n;i++)
#define ff(n) for(int j=0;j<n;j++)
#define pb(x) push_back(x)
#define mp make_pair
#define ll long long
#define mod 1000000007
using namespace std;
vector <int> v[100001];
map <int,int> vis;
int cnt,parent[100001];
void dfssh(int ele)
{
    vis[ele]++;
    f(v[ele].size())
    {
        int ch=v[ele][i];
        if(!vis[ch])
        {
            parent[ch]=ele;
            dfssh(ch);
        }
    }
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    memset(parent,-1,sizeof(parent));
    for(int i=1;i<=n;i++)
        if(parent[i]==-1)
            dfssh(i);
    vis.clear();
    vis[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(parent[i]!=-1)
        {
            if(parent[parent[i]]==-1)
            {
                if(v[i].size()-1>v[parent[i]].size())
                 cnt++;
            }
            else
            {
                if(v[i].size()-1>v[parent[i]].size()-1)
                    cnt++;
            }
        }
    }
    cout<<cnt;
}
