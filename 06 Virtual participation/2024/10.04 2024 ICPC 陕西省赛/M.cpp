#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,x,y;
	cin>>n;
	map<pair<int,int>,array<int,4> >mp;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y; 
		mp[{x-1,y-1}][1]=mp[{x-1,y-1}][2]=1;
		mp[{x,y-1}][2]=mp[{x,y-1}][3]=1;
		mp[{x,y}][3]=mp[{x,y}][0]=1;
		mp[{x-1,y}][0]=mp[{x-1,y}][1]=1;
	}
	int ans=0;
	for(auto i:mp)
	{
		for(auto j:i.second) if(j==1) ans++;
	}
	printf("%.4f",ans*0.25);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
