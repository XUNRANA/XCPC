#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long 
int n,m1,m2,a[N],b[N],c[N],d[N];
void solve()
{
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++) cin>>a[i]>>b[i];
    for(int j=1;j<=m2;j++) cin>>c[j]>>d[j];
    int i=1,j=1,ans=0;
    map<int,int>mp;
    while(i<=m1||j<=m2)
    {
        mp[a[i]]++;
        mp[c[j]]++;
        if(i!=1&&mp.size()==2) ans++;
        int t=min(b[i],d[j]);
        b[i]-=t;
        d[j]-=t;
        if(a[i]!=c[j]) ans+=t-1;
        mp.clear();
        mp[a[i]]++;
        mp[c[j]]++;
        if(b[i]==0) i++;
        if(d[j]==0) j++;
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--) solve();
}
