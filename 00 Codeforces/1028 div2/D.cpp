#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
int a[300010];
int b[300010];
int c[300010];
int x[300010];
int y[300010];
int z[300010];
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        cin>>b[i];
        a[i]=b[i];
    }

    for(int i=1;i<=q;i++) cin>>x[i]>>y[i]>>z[i];
    for(int i=q;i>=1;i--)//倒推a
    {
        a[x[i]]=max(a[x[i]],a[z[i]]);
        a[y[i]]=max(a[y[i]],a[z[i]]);
        if(z[i]!=x[i]&&z[i]!=y[i]) a[z[i]]=0;
    }

    for(int i=1;i<=n;i++) c[i]=a[i];

    for(int i=1;i<=q;i++) c[z[i]]=min(c[x[i]],c[y[i]]);

    for(int i=1;i<=n;i++) 
    if(c[i]!=b[i])//最终不一样、非法
    {
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}