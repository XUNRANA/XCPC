#include <bits/stdc++.h>
using namespace std;
#define N 110
int n,m,k,l;
int x[N],y[N],c[N],p[N],q[N];
vector<int>a[N];
vector<int>b[N];
void solve()
{
    cin>>n>>m>>k>>l;
    for(int i=1;i<=k;i++) cin>>x[i];
    for(int i=1;i<=l;i++) cin>>y[i];
    for(int i=1;i<=m;i++)
    {
        cin>>c[i]>>p[i]>>q[i];
        int x;
        for(int j=1;j<=p[i];j++) cin>>x,a[i].push_back(x);
        for(int j=1;j<=q[i];j++) cin>>x,b[i].push_back(x);
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