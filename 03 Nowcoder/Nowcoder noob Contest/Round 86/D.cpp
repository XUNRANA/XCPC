#include <bits/stdc++.h>
using namespace std;
char s[1010][1010];
int n,m,v[1010][1010],num,x1,x2,y11,y2,ans;
void dfs(int x,int y)
{
    if(x<1||x>n||y<1||y>m) return ;
    if(s[x][y]=='*'||v[x][y]) return ;
    
    v[x][y]=1;
    num++;
    
    x1=max(x1,x);
    x2=min(x2,x);
    y11=max(y11,y);
    y2=min(y2,y);

    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>s[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    if(s[i][j]=='.'&&!v[i][j])
    {
        num=0;
        x1=y11=0;
        x2=y2=1010;
        dfs(i,j);
        if((x1-x2+1)*(y11-y2+1)==num) ans++;
    }
    cout<<ans;
}