#include <bits/stdc++.h>
using namespace std;
#define int long long


int ans[1024][1024];
void fx(int x1,int y1,int x2,int y2)
{
    int l=x2-x1+1;
    for(int x=x1;x<=x2;x++)
    {
        for(int y=y1;y<=y2;y++)
        {
            ans[x][y+l]=ans[x][y]*2;
            ans[x+l][y]=sqrt(ans[x][y]);
            ans[x+l][y+l]=ans[x][y];
        }
    }
}
void solve() 
{
    int n;
    cin>>n;
    ans[1][1]=1;
    ans[1][2]=2;
    ans[2][1]=1;
    ans[2][2]=1;
    for(int i=1;i<n;i++)
    {
        fx(1,1,1<<i,1<<i);
    }
    for(int j=1<<n;j>=1;j--,cout<<"\n")
    for(int i=1;i<=(1<<n);i++) cout<<ans[i][j]<<" ";
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