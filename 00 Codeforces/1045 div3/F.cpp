#include <bits/stdc++.h>
using namespace std;
#define int long long

int h,d;
bool ck(int x)
{
    int c=d/(x+1);//走路的段数
    int need=c*(c+1)/2*(x+1-d%(x+1))+(c+1)*(c+2)/2*(d%(x+1));
    return h+x>need;
}

void solve()
{
    cin>>h>>d;
    int l=0,r=d;//休息的次数
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<l+d<<"\n";
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}