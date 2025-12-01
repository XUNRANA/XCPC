#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,w,a[200010],ans;
void solve()
{
	ans=0;
	cin>>n>>m>>k;
	cin>>w;
	for(int i=1;i<=w;i++) cin>>a[i];
	sort(a+1,a+1+w);
	vector<vector<int>>d(n+2,vector<int>(m+2,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int nx=i+k-1,ny=j+k-1;
			if(nx>n||ny>m) break;
			d[i][j]++;
			d[i][ny+1]--;
			d[nx+1][j]--;
			d[nx+1][ny+1]++;
		} 
	}
	priority_queue<int,vector<int>,less<int>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
			q.push(d[i][j]);
		}
	}
	ans=0;
	for(int i=w;i>=1;i--)
	{
		//cout<<a[i]<<" "<<q.top()<<"\n";
		ans+=a[i]*q.top();
	//	cout<<ans<<"\n";
		q.pop();
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
