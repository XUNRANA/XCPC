#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;
    a=min(a,b);
    cout<<a<<"\n";
    if(a<=20) cout<<"XianHua\n";
    else if(a<=40) cout<<"XiangXun\n";
    else if(a<=60) cout<<"BaoWenBei\n";
    else if(a<=200) cout<<"HunShaZhao\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}