#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,x,y;
	cin>>n;
	vector<pair<int,int>>v;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		v.push_back({x,y});
	}
    cout<<"YES\n";
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++) cout<<v[i].first<<" "<<v[i].second<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

