#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
int b[200010];
int c[200010];
bool ck(int x)
{
    __int128 s=0,s1=0;
    for(int i=1;i<=n;i++) 
    {
        s+=x/c[i];
        s1+=b[i];
    }
    if(s1>s) return 0;
    for(int i=1;i<=n;i++)
    {
        //b[i]不能放到c[a[i]];
        s-=x/c[a[i]];
        if(b[i]>s) return 0;
        s+=x/c[a[i]];
    }
    return 1;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    int l=1,r=1e12;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<l<<"\n";
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
