#include <bits/stdc++.h>
using namespace std;
#define int long long 
int lowbit(int x)
{
    return x&-x;
}
void solve() 
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    int c1=(a&1)+(b&1)+(c&1);
    if(c1==1||c1==2) cout<<"YES\n";
    else if(c1==3) cout<<"NO\n";
    else 
    {
        if(lowbit(a)==lowbit(b)&&lowbit(b)==lowbit(c)) cout<<"NO\n";
        else cout<<"YES\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
