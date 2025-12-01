#include <bits/stdc++.h>
using namespace std;


int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=2;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
    int ans=0;
    for(int i=0;i<31;i++)
    {
        int s1=0,s2=0;
        for(int j=2;j<=n;j++) if(a[j]>>i&1) s1++;
        else s2++;
        if(s1>s2) ans|=1<<i;
    }
    for(int i=1;i<=n;i++) cout<<(a[i]^ans)<<" ";
    cout<<"\n";
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