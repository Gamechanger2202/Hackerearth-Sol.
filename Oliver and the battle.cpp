#include<bits/stdc++.h>
#define f(n) for(i=0;i<n;i++)
#define pb(x) push_back(x)
#define mp make_pair
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i,j;
        cin>>n>>m;
        int a[n][m];
        f(n)
            for(j=0;j<m;j++)
                cin>>a[i][j];
        pair<int,int> sum[]={mp(-1,0),mp(0,-1),mp(+1,0),mp(0,+1),mp(-1,+1),mp(-1,-1),mp(+1,-1),mp(+1,+1)};
        vector<int> cntlist;
        f(n)
            for(j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    int count=1;
                    queue< pair<int,int> > q;
                    q.push(mp(i,j));
                    a[i][j]=-1;
                    while(!q.empty())
                    {
                        pair<int,int > p=q.front();
                        q.pop();
                        for(int k=0;k<8;k++)
                        {
                            pair<int,int> p1;
                            p1.first=p.first+sum[k].first; p1.second=p.second+sum[k].second;
                            if(p1.first<0 || p1.first>=n || p1.second<0 || p1.second>=m) continue;
                            if(a[p1.first][p1.second]==1)
                            {
                                q.push(p1);
                                a[p1.first][p1.second]=-1;
                                count++;
                            }
                        }
                    }
                    cntlist.pb(count);
                }
            }
        if(cntlist.size()==0)
            {
                cout<<"0 0\n";
                continue;
            }
        int ms=*max_element(cntlist.begin(),cntlist.end());
        cout<<cntlist.size()<<" "<<ms<<endl;
    }
    return 0;
}
