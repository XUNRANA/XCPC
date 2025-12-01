#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1,0));

    vector<int>r(n+1,0);
    vector<int>c(m+1,0);
    int mx=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>a[i][j];
            if(a[i][j]>mx)
            {
                mx=a[i][j];
                cnt=1;
            }
            else if(a[i][j]==mx) cnt++;
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {

            if(mx==a[i][j]) r[i]++,c[j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        if(r[i]+c[j]-(a[i][j]==mx)==cnt)
        {
            cout<<mx-1<<"\n";
            return ;
        }
    }

    cout<<mx<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}