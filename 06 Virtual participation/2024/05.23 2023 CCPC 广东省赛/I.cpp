#include <bits/stdc++.h>
using namespace std;
int n,m,l,r,mid,ans;
int ck(int mid,vector<vector<int>>&a)
{
	int px=1,py=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j]<mid) 
		{
			if(i<px||j<py) return 0;
			px=i;
			py=j;
		}
	}	
	return 1;
}
void solve()
{
	cin>>n>>m;
	vector<vector<int>>a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	l=1,r=n*m;
	while(l<=r)
	{
		mid=l+r>>1;
		if(ck(mid,a)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();  
}
