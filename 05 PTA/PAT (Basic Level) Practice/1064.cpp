#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,x;
	cin>>n;
	map<int,int>mp;
	while(n--)
	{
		cin>>x;
		int s=0;
		while(x)
		{
			s+=x%10;
			x/=10;
		}
		mp[s]++;
	}
	vector<int>ans;
	for(auto i:mp) ans.push_back(i.first);
	int f=0;
	cout<<ans.size()<<"\n";
	for(auto i:ans)
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
	// cin>>T;
	while(T--) solve(); 
}
