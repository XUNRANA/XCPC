#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[11];
void init()
{
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=10;i++) f[i]=f[i-1]+f[i-2];
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int w,l,h;
        cin>>w>>l>>h;
        if(w>l) swap(w,l);
        if(l>h) swap(l,h);
        if(w>l) swap(w,l);
        if(h>=f[n]+f[n-1]&&l>=f[n]&&w>=f[n]) cout<<"1";
        else cout<<"0";
    }
    cout<<"\n";
}
signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}