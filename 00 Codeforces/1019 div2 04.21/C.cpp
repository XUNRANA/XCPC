#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010];
bool ck()
{
    int c0=0;
    int c1=0;
    int l=-1,r=-1;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) c0++;
        else c1++;
        if(c0>=c1&&l==-1) l=i;
        if(c0>=c1) 
        {
            if(f&&abs(i-f)>1) return 1;
            if(!f) f=i;
        }
    }

    c0=c1=f=0;
    for(int i=n;i>=1;i--)
    {
        // 1 1 0
        if(a[i]==0) c0++;
        else c1++;
        if(c0>=c1&&r==-1) r=i; 
        if(c0>=c1) 
        {
            if(f&&abs(i-f)>1) return 1;
            if(!f) f=i;
        }
    }
    if(l!=-1&&r!=-1&&l+1<r) return 1;


    return 0;
}
void solve() 
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x<=k) a[i]=0;
        else a[i]=1;
    }
    if(ck()) cout<<"YES\n";
    else cout<<"NO\n";
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