#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[1000010];
int s1[1000010];
int s2[1000010];
int a[500010];
int b[500010];
int w[500010];
void solve()
{
    int n,k;
    cin>>n>>k;
    int j=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>w[i];
        c[++j]=a[i];
        c[++j]=b[i]+1;
    }
    sort(c+1,c+1+2*n);
    j=unique(c+1,c+1+2*n)-c-1;
    for(int i=1;i<=n;i++)
    {
        int idx=lower_bound(c+1,c+1+j,a[i])-c;
        s1[idx]++;
        s2[idx]^=w[i];
        idx=lower_bound(c+1,c+1+j,b[i]+1)-c;
        s1[idx]--;
        s2[idx]^=w[i];
    }

    
    for(int i=1;i<=j;i++) 
    {
        s1[i]+=s1[i-1];
        s2[i]^=s2[i-1];
    }

    int ans=-1;
    for(int i=1;i<=j;i++) 
    if(s1[i]>=k) ans=max(ans,s2[i]);
    
    cout<<ans<<"\n";
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
