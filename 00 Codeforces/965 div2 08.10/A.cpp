#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int x,y,k,s=0;
	cin>>x>>y>>k;
	vector<pair<int,int>>v;
	for(int i=1;i<k;i++) 
	{
		if(y>=0) 
		{
			s+=-i;
			v.push_back({x,-i});
		}
		else
		{
			s+=i;
			v.push_back({x,i});
		}
	}
	v.push_back({x,k*y-s});
	for(auto i:v) cout<<i.first<<" "<<i.second<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

