#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
int b[2010];
int n,m,k;
bool ck(int x,int y)
{
    for(int i=1;i<=k;i++) b[i]=0;
    for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) b[a[i][j]]=1;
    for(int i=1;i<=k;i++) if(!b[i]) return 0;
    return 1;
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>a[i][j];
        }
    }

    int l1=1,r1=n;
    while(l1<=r1)
    {
        int m1=l1+r1>>1;
        if(ck(m1,m)) r1=m1-1;
        else l1=m1+1;
    }
    int r=m;
    int ans=0;
    for(int i=l1;i<=n;i++)
    {
        while(ck(i,r)) r--;
        ans+=m-r;
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
