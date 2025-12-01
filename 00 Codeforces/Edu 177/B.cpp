#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
int pre[100010];
int n,k,x,s;
bool ck(int m)
{
    return (s*k-m/n*s-pre[m%n])>=x;
}
void solve() 
{
    cin>>n>>k>>x;
    s=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        s+=a[i];
        pre[i]=pre[i-1]+a[i];
    }
    if(s*k<x)
    {
        cout<<"0\n";
        return ;
    }
    int l=1,r=n*k;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) l=m+1;
        else r=m-1;
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
}