#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
int n,a[100010];
int ksm(int a,int b,int p)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
void solve() 
{
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    if(mx==0)
    {
        cout<<"1\n";
        return ;
    }
    int g=0;
    for(int i=1;i<=min(n,60ll);i++)
    {
        g=__gcd((1ll<<(i-1))-a[i],g);
    }
    if(g==0)
    {
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;i++)
    if(ksm(2,i-1,g)!=a[i])
    {
        cout<<"-1\n";
        return ;
    }
    cout<<g<<"\n";
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
