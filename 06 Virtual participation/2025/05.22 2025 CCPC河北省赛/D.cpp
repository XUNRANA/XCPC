#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[1000010];
int p[1000010];
int res;
int fx(int x)
{
    int ans=0;
    res=0;
    for(int i=2,j=1;i<=n;i++) 
    {
        while(a[i]-a[j]>x) j++;
        if(j<i&&a[i]-a[j]<=x) 
        {
            res+=(i-j)*a[i]-(p[i-1]-p[j-1]);
            ans+=i-j;
        }
    }
    return ans;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
    int l=1,r=a[n]-a[1];
    while(l<=r)
    {
        int m=l+r>>1;
        if(fx(m)>=k) r=m-1;
        else l=m+1;
    }
    int cnt=fx(l);
    cout<<res-(cnt-k)*l<<"\n";
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
