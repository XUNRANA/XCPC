#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,d,l;
bool ck(int x)
{
    int cnt=x/n;
    int mod=x%n;
    if(mod==0) return (n+cnt*d)>=l;
    return (mod+(cnt+1)*d)>=l;
}
void solve()
{
    cin>>n>>d>>l;
    int l1=1,r1=1e9;
    while(l1<=r1)
    {
        int m1=l1+r1>>1;
        if(ck(m1)) r1=m1-1;
        else l1=m1+1;
    }
    cout<<l1<<" "<<(l-n-1)*n+1<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}