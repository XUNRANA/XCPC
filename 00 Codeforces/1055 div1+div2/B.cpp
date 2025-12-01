#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,x1,y11,x2,y2;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool ck(int x)
{
    for(int i=0;i<4;i++)
    {
        int nx=x1+x*dx[i];
        int ny=y11+x*dy[i];
        nx=min(nx,n);
        nx=max(nx,0ll);

        ny=min(ny,n);
        ny=max(ny,0ll);

        if(max(abs(x2-nx),abs(y2-ny))>x) return 0;
    }
    return 1;
}
void solve()
{
    cin>>n>>x1>>y11>>x2>>y2;
    int l=1,r=1e9;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<l<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}