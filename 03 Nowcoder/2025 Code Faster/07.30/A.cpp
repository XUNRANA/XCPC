#include <bits/stdc++.h>
using namespace std;
vector<array<int,2>>a;
void solve()
{
    int x,y;
    cin>>x>>y;
    int res=1e9;
    for(int i=-10;i<=10;i++)
    {
        for(int j=-10;j<=10;j++)
        {
            int nx=x+i;
            int ny=y+j;
            int ans=abs(i)+abs(j);
            if(nx>=1&&nx<=ny&&ny<=1e9)
            {
                if((ny+nx)%10==(ny-nx+100)%10)
                {
                    res=min(res,ans);
                }
            }
        }
    }
    cout<<res<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}