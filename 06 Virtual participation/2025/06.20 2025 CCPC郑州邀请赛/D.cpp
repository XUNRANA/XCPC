#include <bits/stdc++.h>
using namespace std;
int is(int x)
{
    int y=sqrt(x);
    return y*y==x;
}
int fx(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}

void solve()
{
    int x;
    cin>>x;
    if(is(x)&&is(fx(x))) cout<<"Yes\n";
    else cout<<"No\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

