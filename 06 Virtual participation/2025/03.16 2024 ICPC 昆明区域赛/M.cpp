
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1010][1010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) a[i][j]=0;
    queue<pair<int,int>>q;
    q.push({1,1});
    int i=1;
    a[1][1]=i++;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(y+1<=m&&!a[x][y+1])
        {
            a[x][y+1]=i++;
            q.push({x,y+1});
        }
        if(x+1<=n&&!a[x+1][y]) 
        {
            a[x+1][y]=i++;
            q.push({x+1,y});
        }
    }
    for(int i=1;i<=n;i++,cout<<"\n")
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j]<<" ";
        }
    }
} 
 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}