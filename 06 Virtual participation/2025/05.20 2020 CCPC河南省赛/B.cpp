#include <bits/stdc++.h>
using namespace std;
#define int long long
int d[100010];
int p[100010];
int a[100010];
int st[100010];
int ans[100010];

int f[1000010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    
    int cnt=0;
    for(int i=m;i>=1;i--)
    if(!st[m/i])
    {
        ans[cnt++]=m/i;
        st[m/i]=1;
    }


    for(int i=1;i<=n;i++)
    for(int j=0;j<cnt;j++)
    f[ans[j]/d[i]]=max(f[ans[j]/d[i]],f[ans[j]]+1ll*ans[j]*p[i]);

    int res=0;
    for(int i=0;i<=m;i++) res=max(res,f[i]);
    cout<<res<<"\n";
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
