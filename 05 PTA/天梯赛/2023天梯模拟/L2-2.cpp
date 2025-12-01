#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<pair<string,string>>d,ans;
	for(int i=1;i<=n;i++)
	{
		string a,b,c;
		cin>>a>>b>>c;
		d.push_back({a,c});
	}
	sort(d.begin(),d.end());
	string pre="00:00:00";
	for(auto i:d) 
	{
		if(i.first==pre) pre=i.second;
		else 
		{
			ans.push_back({pre,i.first});
			pre=i.second;
		}
//		cout<<i.first<<" "<<i.second<<"\n";
	}
	if(pre!="23:59:59") ans.push_back({pre,"23:59:59"});
	for(auto i:ans) cout<<i.first<<" - "<<i.second<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int T=1;
//	cin>>T;
	while(T--) solve();
}
