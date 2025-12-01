#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m,a,b;
	cin>>n>>m;
	vector<pair<int,int>>v;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		v.push_back({a,b});
	}
	
	sort(v.begin(),v.end());
	
	if(v[0].first<v[0].second)
	{
		cout<<"No\n";
		return ;
	}
	
	for(int i=1;i<v.size();i++)
	{
		int aa=v[i-1].first;
		int bb=v[i-1].second;
		a=v[i].first;
		b=v[i].second;		
		if(b==bb+a-aa||b<a-aa)
		{
			continue;
		}
		cout<<"No\n";
		return ;
	}
	cout<<"Yes\n";
	

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
