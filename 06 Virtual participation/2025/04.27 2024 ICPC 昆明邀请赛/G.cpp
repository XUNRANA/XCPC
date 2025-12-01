#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[1000010];
void solve() 
{
    int x;
    cin>>x;
    if(x%4==0||x==1) cout<<"impossible\n";
    else
    {
        for(int i=0;i<x;i++) ans[i]=i;
        swap(ans[0],ans[1]);
        for(int i=4;i<x;i+=4) swap(ans[i],ans[i-1]);
        for(int i=0;i<x;i++) cout<<ans[i]<<" \n"[i==x-1];
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