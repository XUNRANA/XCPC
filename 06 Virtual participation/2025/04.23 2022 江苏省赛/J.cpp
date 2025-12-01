#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int cal(int x,int a,int b,int c)
{
    if(!x) return 0;
    else if(x==1) return c;
    else if(x&1) return cal(x>>1,a*2+b,b,b+c);
    else return cal(x>>1,a,a+2*b,a+c);
}
void solve() 
{
    int n;
    cin>>n;
    int ans=cal(n,1,0,0);
    if(ans>=64) cout<<"0\n";
    else cout<<(1ull<<ans)<<"\n";

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