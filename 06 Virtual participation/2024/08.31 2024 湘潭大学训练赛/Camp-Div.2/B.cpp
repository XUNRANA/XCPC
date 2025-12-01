#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
#define P 1331 
#define mod 998244353
int n,m,a[N],cnt;
set<pair<int,int>>st;
set<int>is;
bool ck(int x)
{
	x++;
	while(x+m-1<=n&&st.count({x,x+m-1})) x+=m;
	if(is.count(x)) return 1;
	else return 0;
}
void solve()
{
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>m) 
		{
			cout<<"NO\n";
			return ;
		}
	}
	if(m==1)
	{
		cout<<"YES\n";
		return ;
	}
	map<int,int>mp;
	for(int i=1,j=1;j<=n;j++)
	{
		mp[a[j]]++;
		if(j>=m+1) 
		{
			mp[a[i]]--;
			if(mp[a[i]]==0) mp.erase(a[i]);
			i++;
		}
		if(j>=m&&mp.size()==m) st.insert({i,j});
	}
	mp.clear();
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		if(mp.count(a[i])) break;
		v.push_back(i);
		mp[a[i]]++;
	}
	is.insert(n+1);
	mp.clear();
	for(int i=n;i>=1;i--)
	{	
		if(mp.count(a[i])) break;
		is.insert(i);
		mp[a[i]]++;
	}
	for(auto i:v)
	{
		if(ck(i))
		{
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
