#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int x,y;
    cin>>x>>y;
    int cnt1=0,cnt=0;
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i+j>=x||abs(i-j)>=y)
            {
                cnt++;
            }
            cnt1++;
        }
    }
    
    // cout<<cnt<<" "<<cnt1<<"\n";
    printf("%.10f",1.0*cnt/cnt1);
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