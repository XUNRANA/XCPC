#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
char a[1010][1010];
void ck(int sx,int sy,int tx,int ty)
{
	if(sx<=n/2&&sy<=m/2)
	{
		string s;
//		sx,sy    sx,ty
		
		
		
//		tx,sy    tx,ty
		
		
		for(int i=sy;i<=ty;i++) s+=a[sx][i];
		
		for(int i=sx+1;i<=tx;i++) s+=a[i][ty];
		
		for(int i=ty-1;i>=sy;i--) s+=a[tx][i];
		
		for(int i=tx-1;i>=sx+1;i--) s+=a[i][sy];
		
//		cout<<s<<"\n";
		int n=s.size();
		s=s+s;
		for(int i=0;i<n;i++) if(i+3<2*n&&s.substr(i,4)=="1543") ans++;
		ck(sx+1,sy+1,tx-1,ty-1);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	  
	  
	ans=0;
	ck(1,1,n,m);
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
