#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,k,a[300010],s;
map<int,int>mp;
int sg(int i)
{
	if(mp[i]) return mp[i];
	if(i==0) return 0;
	else if(i==1) return 1;
	else 
	{
		int x=1;
		map<int,int>is;
		while(x<=i)
		{
			is[sg(i-x)]=1;
			x=x*p;
		}
		int res=0;
		while(is.count(res)) res++;
		return mp[i]=res;
	}
}
void solve()
{

	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(p&1)
	{
		for(int i=1;i<=n;i++) s^=a[i]&1;
	}
	else
	{ 
		for(int i=1;i<=n;i++)
		{
			int t=a[i]%(p+1);
			if(t==p) s^=2;
			else s^=t&1;
		}	
	}
	if(s) cout<<"GOOD\n";
	else cout<<"BAD\n";	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
