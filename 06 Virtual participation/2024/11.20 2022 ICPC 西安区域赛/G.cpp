#include <bits/stdc++.h>
using namespace std;

vector<string>g[100010];
void solve()
{
	int n;
	cin>>n;	
	map<string,int>mp;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s.size()==1) mp[s]=2;
		else mp[s]=1;
		g[s.size()].push_back(s);
	}
	
	if(!g[1].size())
	{
		cout<<"0\n";
		return ;
	}
	int ans=1;
	for(int i=2;i<=100000;i++)
	{
		int f=0;
		for(auto s:g[i])
		{
			string t1=s.substr(0,i-1);
			string t2=s.substr(1,i-1);
			if(mp.count(t1)&&mp.count(t2)&&mp[t1]==2&&mp[t2]==2)
			{
				mp[s]=2;
				f=1;
				ans=max(ans,i);
			}
		}
		if(!f)
		{
			cout<<ans<<"\n";
			return ;
		}		
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
