#include <bits/stdc++.h>
using namespace std;
void solve()
{
	vector<int>c(7,0);
	vector<int>g[7];
	for(int i=1;i<=5;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		c[a]++;
		c[b]++;
	}
	map<int,int>mp;
	for(int i=1;i<=6;i++) mp[c[i]]++;
	if(mp.count(4)) cout<<"2,2-dimethylbutane\n";
	else if(mp.count(3)&&mp[3]==2) cout<<"2,3-dimethylbutane\n";
	else if(mp[2]==4) cout<<"n-hexane\n";
	else 
	{
		for(int i=1;i<=6;i++) if(c[i]==3)
		{
			int cnt=0;
			for(auto j:g[i]) if(c[j]==2) cnt++;
			if(cnt==2) cout<<"3-methylpentane\n";
			else cout<<"2-methylpentane\n";
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--) solve();
}
