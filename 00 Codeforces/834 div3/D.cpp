#include <bits/stdc++.h>
using namespace std;
#define int long long
int fx5(int x)
{
    int c=0;
    while(x%5==0)
    {
        x/=5;
        c++;
    }
    return c;
}
int fx2(int x)
{
    int c=0;
    while(x%2==0)
    {
        x/=2;
        c++;
    }
    return c;
}
void solve()
{
    int x,y;
    cin>>x>>y;
    int c2=fx2(x);
    int c5=fx5(x);
    int cnt=abs(c2-c5);
    int f=(c2>c5);
    int res=1;
    while(cnt)
    {
        if(f)
        {
            if(res*5<=y) res*=5;
        }
        else 
        {
            if(res*2<=y) res*=2;
        }
        cnt--;   
    }
    while(res*10<=y) res*=10;
    res=y/res*res;
    cout<<x*res<<"\n";
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


