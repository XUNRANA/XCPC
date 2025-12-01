#include <bits/stdc++.h>
using namespace std;
#define int long long


int p[]={2,3,5,7};
int lcm(int x,int y)
{
    return x/__gcd(x,y)*y;
}
int fx(int l,int r,int x)
{
    return r/x-(l+x-1)/x+1;
}
void solve()
{
    int l,r;
    cin>>l>>r;
    int s=0;
    for(int i=1;i<(1<<4);i++)
    {
        int x=1;
        int c=0;
        for(int j=0;j<4;j++) 
        if(i>>j&1) 
        {
            x=lcm(x,p[j]);
            c++;
        }

        fx(l,r,x);
        if(c&1) s+=fx(l,r,x);
        else s-=fx(l,r,x);
    }
    // cout<<s<<"?\n";
    cout<<r-l+1-s<<"\n";
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