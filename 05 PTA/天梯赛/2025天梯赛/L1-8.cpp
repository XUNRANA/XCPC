#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
int r[1010],c[1010];
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<array<int,3>>b;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>a[i][j];
		int x=a[i][j]+(1ll<<30);
		b.push_back({-x,i,j});
	}
	sort(b.begin(),b.end());
	
	for(int i=0;i<n*m;i++) 
	{
		int x=b[i][1];
		int y=b[i][2];
		if(k)
		{
			if(!r[x]&&!c[y])
			{
				k--;
				r[x]=1;
				c[y]=1;
			}
		}
	}
	for(int i=1;i<=n;i++) 
	{
		if(r[i]) continue;
		int f=0;
		for(int j=1;j<=m;j++)
		if(!c[j]) 
		{
			if(f) cout<<" ";
			cout<<a[i][j];
			f=1;
		}
		cout<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
