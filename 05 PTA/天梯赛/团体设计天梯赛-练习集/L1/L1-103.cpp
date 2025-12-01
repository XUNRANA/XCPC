#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
	int cnt=0;
	while(x>10)
	{
		cnt++;
		int res=1;
		while(x)
		{
			res*=x%10;
			x/=10;
		}
		x=res;
	}
	return cnt;
}
void solve()
{
	int a,b;
	cin>>a>>b;
	map<int,vector<int>>mp;
	int mx=0;
	for(int i=a;i<=b;i++) 
	{
		mp[f(i)].push_back(i);
		mx=max(mx,f(i));
	}
	cout<<mx<<"\n";
	sort(mp[mx].begin(),mp[mx].end());
	int f=0;
	for(auto i:mp[mx])
	{
		if(f) cout<<" ";
		cout<<i;
		f=1;
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

