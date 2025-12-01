#include <bits/stdc++.h>
using namespace std;
#define int long long


int n,m,k;
char a[110][31][31];
int cnt[110];
int b[110];
bool cmp(int b1,int b2)
{
    return cnt[b1]>cnt[b2];
}
void solve()
{
    cin>>n>>m>>k;
    for(int k1=1;k1<=k+1;k1++)
    {
        b[k1]=k1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[k1][i][j];
            }
        }

        for(int i=2;i<=n-1;i++)
        {
            for(int j=2;j<=m-1;j++)
            {
                if(a[k1][i][j]!=a[k1][i-1][j])
                if(a[k1][i][j]!=a[k1][i][j-1])
                if(a[k1][i][j]!=a[k1][i+1][j])
                if(a[k1][i][j]!=a[k1][i][j+1])
                {
                    cnt[k1]++;
                }
            }
        }
    }

    sort(b+1,b+1+k+1,cmp);
   
    vector<vector<int>>ans;
    for(int i=2;i<=k+1;i++) 
    {
        int x=b[i-1];
        int y=b[i];
        for(int i1=1;i1<=n;i1++)
        {
            for(int j1=1;j1<=m;j1++)
            {
                if(a[x][i1][j1]!=a[y][i1][j1])
                {
                    ans.push_back({1,i1,j1});
                }
            }
        }
        ans.push_back({2,y});
    }
    cout<<b[1]<<"\n";
    cout<<ans.size()<<"\n";
    for(auto j:ans)
    {
        for(auto j1:j) cout<<j1<<" ";
        cout<<"\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}