#include <bits/stdc++.h>
using namespace std;
string s;
#define int long long
int n,m,u,v,ans;
signed main()
{
	while(cin>>n>>m)
	{
		cin>>s;
		s=" "+s;
		vector<pair<int,int>>p;
		vector<int>d(n+1,0);
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			if(s[u]!=s[v]) 
			{
				d[u]++;
				d[v]++;
				p.push_back({u,v});
			}
		}
		ans=0;
		for(int i=0;i<p.size();i++) ans+=(d[p[i].first]-1)*(d[p[i].second]-1);
		cout<<ans<<"\n";
	}
}
