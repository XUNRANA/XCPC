#include <bits/stdc++.h>
using namespace std;
#define int long long

char a[3][100010];
int vt[3][100010];
int f;
int m,x,y;
void dfs(int d,int i,int j)
{
    if(i==3&&j==y) 
    {
        f=1;
        return ;
    }
    if(i<1||i>2||j<1||j>m||vt[i][j]) 
    {
        return ;
    }
    if(a[i][j]=='I')
    {
        vt[i][j]=1;
        if(d==1) dfs(d,i+1,j);
        else if(d==2) dfs(d,i-1,j);
        else if(d==3) dfs(d,i,j-1);
        else dfs(d,i,j+1);
        vt[i][j]=0;
    }
    else
    {
        vt[i][j]=1;
        if(d==1||d==2) 
        {
            dfs(3,i,j-1);
            dfs(4,i,j+1);
        }
        else if(d==3||d==4)  
        {
            dfs(1,i+1,j);
            dfs(2,i-1,j);
        }
        vt[i][j]=0;
    }
}
//down 1
//up   2
//left 3 
//right 4
void solve()
{
    cin>>m>>x>>y;
    for(int i=1;i<=2;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    f=0;
    dfs(1,1,x);
    if(f) cout<<"YES\n";
    else cout<<"NO\n";
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
