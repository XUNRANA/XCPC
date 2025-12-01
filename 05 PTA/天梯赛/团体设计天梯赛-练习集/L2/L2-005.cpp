#include <bits/stdc++.h>
using namespace std;
#define int long long

set<int>a[51];
double ans[51][51];
double f(int x,int y)
{
	set<int>st,st1;
	for(auto i:a[x]) st.insert(i);
	st1=st;
	int cnt=0;
	for(auto i:a[y]) 
	{
		st.insert(i);
		if(st1.count(i)) cnt++;
	}
	return 100.0*cnt/st.size();
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			a[i].insert(x);
		}
	}
	int k;
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans[i][j]=f(i,j);
		}
	}
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		printf("%.2f%%\n",ans[x][y]);
//		cout<<ans[x][y]<<"\n";
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

