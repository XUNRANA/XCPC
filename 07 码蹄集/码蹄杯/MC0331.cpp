#include <bits/stdc++.h>
using namespace std;
#define int long long
int fxx(int x)//1*1+2*2+...x*x;
{
    return x*(x+1)*(2*x+1)/6;
}
int fx(int x)//1+2+...x;
{
    return (1+x)*x/2;
}
int get(int x)
{
    if(!x) return 0;
    int l=1,r=1e9;
    while(l<=r)
    {
        int m=l+r>>1;
        if(fx(m)<=x) l=m+1;
        else r=m-1; 
    }
    l--;
    return fxx(l)+(x-fx(l))*(l+1);
}
void solve()
{
    int l,r;
    cin>>l>>r;
    cout<<get(r)-get(l-1)<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
