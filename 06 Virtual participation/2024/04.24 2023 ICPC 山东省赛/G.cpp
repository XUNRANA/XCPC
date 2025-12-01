#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,t,ans;
	cin>>n;
	map<int,vector<int> >mp;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mp[t-i].push_back(t);
	}
	ans=0;
	for(auto i:mp)
	{
		for(int j=i.second.size()-1;j>=0;j--)
		{
			if(i.second[j]>0&&j>=1&&i.second[j]+i.second[j-1]>=0)
			{
				ans+=i.second[j]+i.second[j-1];
				j--;
			}
			else break;	
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
	cin>>T;
	while(T--) solve();
}
