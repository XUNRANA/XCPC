#include <bits/stdc++.h>
using namespace std;
#define int long long
bool is(int x)
{
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void solve()
{
    int l,r;
    cin>>l>>r;
    if(r<=3)
    {
        cout<<"-1\n";
        return ;
    }
    for(int i=l;i<=r;i++)//4 6 8 10 11 13
    if(i%2==0&&i!=2)
    {
        cout<<2<<" "<<i-2<<'\n';
        return ;
    }

    if(is(l)) cout<<"-1\n";
    else 
    {
        for(int i=2;i*i<=l;i++) 
        if(l%i==0)
        {
            cout<<i<<" "<<l-i<<"\n";
            return ;
        }
    }
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