#include <bits/stdc++.h>
using namespace std;
#define int long long

int f1(int x)
{  
    //奇数步到x
    int cnt=(x+1)/2;
    if(!x) return 3;
    if(cnt&1) return cnt;
    else return cnt+1;
}
int f0(int x)
{
    //偶数步到x
    int cnt=(x+1)/2;
    if(cnt&1) return cnt+1;
    return cnt;
}
void solve()
{
    int x,y,X,Y;
    cin>>x>>y>>X>>Y;
    x=abs(x-X);
    y=abs(y-Y);
    cout<<min(max(f0(x),f0(y)),max(f1(x),f1(y)))<<"\n";
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