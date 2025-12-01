#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    int g=__gcd(x,y);
    x/=g;
    y/=g;
    g=__gcd(a,b);
    a/=g;
    b/=g;
    int ans=0;
    while(x&&y)
    {
        if(x>y) swap(x,y);
        if((x+y)%(a+b)) 
        {
            cout<<"-1\n";
            return ;
        }
        int k=(x+y)/(a+b);
        if(x%a==0)
        {
            x=x/a;
            y=k-x;
            ans++;
        }
        else if(y%a==0)
        {
            x=y/a;
            y=k-x;
            ans++;
        }
        else
        {
            cout<<"-1\n";
            return ;
        }
    }
    cout<<ans+1<<"\n";
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