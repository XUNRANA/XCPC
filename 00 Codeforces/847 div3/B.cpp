#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,s,r;
int a[51];
void solve()
{
    cin>>n>>s>>r;
    r=s-r;

    s-=r;
    n--;
    for(int i=1;i<=n;i++) a[i]=1;
    s-=n;
    int i=1;
    while(s)
    {
        int t=min(s,r-1);
        a[i++]+=t;
        s-=t;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<r<<"\n";

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