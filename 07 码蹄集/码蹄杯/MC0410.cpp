#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[300010];
int fx(int l,int r)
{
    if(l>r) return 0;
    return (r+l)*(r-l+1)/2;
}

int ck(int x)
{
    int ans=0;
    for(int i=1;i<=n;i++) ans+=max(a[i]-x+1,0ll);
    return ans;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1e9,res=-1;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)>=k) l=m+1,res=m;
        else r=m-1; 
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=fx(res,a[i]);
    ans-=(ck(res)-k)*res;
    cout<<ans<<"\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

