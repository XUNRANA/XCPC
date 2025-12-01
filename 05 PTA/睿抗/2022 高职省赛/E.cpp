#include <bits/stdc++.h>
using namespace std;




int fx1(int x)
{
    int r=0;
    while(x)
    {
        r+=x%10;
        x/=10;
    }
    return r;
}

int fx2(int x)
{
    int r=1;
    while(x)
    {
        r*=x%10;
        x/=10;
    }
    return r;
}


void solve()
{
    int a,b;
    cin>>a>>b;
    a=fx1(a);
    b=fx2(b);
    if(b>a) swap(b,a);
    cout<<a<<b<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
