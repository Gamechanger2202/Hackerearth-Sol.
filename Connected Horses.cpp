#include<bits/stdc++.h>
#define f(n) for(int i=0;i<n;i++)
#define ff(m) for(int j=0;j<m;j++)
#define pb(x) push_back(x)
#define mp make_pair
#define ll long long
#define mod 1000000007
using namespace std;
int board[1001][1001];
int cnt,n,m;
void dfs(int a,int b)
{
    int x,y;
    board[a][b]=-1;
    pair<int,int> s[]={mp(-2,-1),mp(-2,+1),mp(+1,+2),mp(-1,-2),mp(+2,-1),mp(+2,+1),mp(+1,-2),mp(-1,+2)};
    f(8)
    {
        x=s[i].first+a; y=s[i].second+b;
        if(board[x][y]==1 && x>=0 && x<n && y>=0 && y<m)
        {
            cnt++;
            dfs(x,y);
        }
    }
}
ll int fact[2303320];
int main()
{

    fact[0]=1;
    for(ll int i=1;i<=2000000;i++)
        fact[i]=(fact[i-1]*i)%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int q,x,y;
        cin>>n>>m>>q;
        memset(board,0,sizeof(board));
        queue <ll int> v;
        f(q)
        {
            cin>>x>>y;
            board[--x][--y]=1;
        }
        f(n)
            ff(m)
            {
                if(board[i][j]==1)
                {
                    cnt=1;
                    dfs(i,j);
                    v.push(cnt);
                }
            }
        ll int ans=1;
        while(!v.empty())
        {
            ll an=v.front();
            an=an%mod;
            ans=(ans*fact[an])%mod;
            v.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
