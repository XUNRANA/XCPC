#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,x,y;
int a[100010];
int b[100010];
int c[100010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x>>y;
            c[i]+=x;
            a[i]-=x;
            a[i]+=y;
        }
        mx=max(mx,c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
        if(c[i]==mx) cout<<"*";
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
}

