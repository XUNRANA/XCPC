#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100][100];
void solve()
{
	int n,m,h;
	cin>>n>>m>>h;
	int x=-1,y=-1;
	int ans=0;
    int mx=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=0) continue;
			int cnt=0;
			for(int i1=i-1;i1>=1;i1--) if(a[i1][j]>=h) break;
			else if(a[i1][j]<0) cnt++;
			
			for(int i1=i+1;i1<=n;i1++) if(a[i1][j]>=h) break;
			else if(a[i1][j]<0) cnt++;
			
			for(int j1=j-1;j1>=1;j1--) if(a[i][j1]>=h) break;
			else if(a[i][j1]<0) cnt++;
			
			for(int j1=j+1;j1<=m;j1++) if(a[i][j1]>=h) break;
			else if(a[i][j1]<0) cnt++;
			
			if(cnt>=3)
			{
				if(cnt>mx)
				{
                    mx=cnt;
					x=i-1;
					y=j-1;
				}
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	cout<<x<<" "<<y<<"\n";
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
