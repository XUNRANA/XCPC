#include <bits/stdc++.h>
using namespace std;
int a[510][510],b[510][510],n,m,x,y,ans,k,mx;
void solve()
{
    ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++) 
    {
        cin>>x>>y;
        a[x][y]++;
    }
    if(n==1||m==1) 
    {
        cout<<k;
        return ;
    }
    x=n/2+1;
    y=m/2+1;
    mx=max(abs(x-1),abs(y-1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]&&abs(i-x)+abs(j-y)<=mx) ans+=a[i][j];
        }
    }
    cout<<ans;
    
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
//	cin>>t1;
	while(t1--) solve(); 
}