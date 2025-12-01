#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,p,q;
void gcd(int a,int b,int &p,int &q,int c,int d)
{
    if(a<b&&c>d) p=1,q=1;
    else
    {
        gcd(d%c,c,q,p,b-(d/c)*a,a);
        q+=(d/c)*p;
    }
}
void solve()
{
    cin>>a>>b>>c>>d;
    gcd(a,b,p,q,c,d);
    cout<<q<<"\n";
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