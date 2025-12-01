#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
char a[1010][1010];
int vt[1010][1010][5][2];
vector<pair<int,int>>v={{-1,0},{1,0},{0,-1},{0,1}};
void solve()
{
    ans=1e9;
    memset(vt,0x3f3f3f3f,sizeof(vt));
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) cin>>a[i][j];
    queue<array<int,5>>q;
    q.push({1,1,0,0,0});//上
    q.push({1,1,0,1,0});//下
    q.push({1,1,0,2,0});//左
    q.push({1,1,0,3,0});//右
    q.push({1,1,0,4,0});//全能
    while(!q.empty())
    {
		int x=q.front()[0];
		int y=q.front()[1];
		int d=q.front()[2];
		int w=q.front()[3];
		int f=q.front()[4];
        q.pop();
        if(x<1||x>n||y<1||y>m) continue;
        if(d>=vt[x][y][w][f]) continue;
        vt[x][y][w][f]=d;
        if(a[x][y]=='X')
        {
            if(f==1||w==4) continue;
            f=1;
        }
        if(x==n&&y==m) ans=min(ans,d);
        for(int i=0;i<4;i++)
        {
            if(w==i) continue;
            q.push({x+v[i].first,y+v[i].second,d+1,w,f});
        }
    }
    if(ans==1e9) ans=-1;
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--) solve();
}
