#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,T;
    cin>>n>>T;
    int s=0;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        s++;
        x--;
        if(x==0) continue;
        if(s+x-1<=T) s+=x;
        else//T+1;
        {
            //一点都不看
            if(s-T>y) continue;
            //全看
            if(s+x-1-T<=y) s+=x;
            else//看一部分
            {
                s=T+y+1;
            }
        }
    }
    cout<<s<<"\n";
}
signed main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}