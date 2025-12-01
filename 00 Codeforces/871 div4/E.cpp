#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010][1010];
int fa[1000010];
int sz[1000010];
int find(int x)
{
    return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y,int x1,int y1)
{
    // cout<<x<<" "<<y<<" "<<x1<<" "<<y1<<"\n";
    
    int a=(x-1)*m+y;
    int b=(x1-1)*m+y1;
    // cout<<sz[find(a)]<<" "<<sz[find(b)]<<"!!\n";
    if(find(a)!=find(b))
    {
        sz[find(a)]+=sz[find(b)];
        fa[find(b)]=find(a);
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
    {
        cin>>a[i][j];
        sz[(i-1)*m+j]=a[i][j];
        fa[(i-1)*m+j]=(i-1)*m+j;
    }

    for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++)
    {
        if(a[i][j])
        {
            if(i+1<=n&&a[i+1][j])
            {
                merge(i,j,i+1,j);
            }
            if(j+1<=m&&a[i][j+1])
            {
                merge(i,j,i,j+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans=max(ans,sz[find((i-1)*m+j)]);
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
