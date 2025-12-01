#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[10][10];
void dfs(int x,int y)
{
    if(x==n&&y==m+1)
    {
        ans++;
        return ;
    }
    if(y==m+1)
    {
        x++;
        y=1;
    }

    if(!a[x][y])
    {
        set<int>st;
        for(int i=1;i<x;i++) st.insert(a[i][y]);
        for(int j=1;j<y;j++) st.insert(a[x][j]);
        for(int j=1;j<=4;j++) 
        {
            if(st.count(j)) continue;
            a[x][y]=j;
            dfs(x,y+1);
            a[x][y]=0;
        }
    }
}
void solve() 
{
    cin>>n>>m;
    n=min(n,4ll);
    m=min(m,4ll);
    ans=0;
    dfs(1,1);
    cout<<ans<<"\n";
}     


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}