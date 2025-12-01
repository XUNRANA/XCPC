#include <bits/stdc++.h>
using namespace std;
int n,h,w,a,b,f;
vector<pair<int,pair<int,int>> >v;
vector<int>ans;
void dfs(int i,int s)
{
	if(s==h*w) 
	{
		f=1;
		return ;
	}
	for(int j=0;j<i;j++) 
	{
		ans.push_back(j);
		dfs(j,s+v[j].first);
		ans.pop_back();
	}
}
int main()
{
	cin>>n>>h>>w;
	for(int i=1;i<=n;i++) 
	{
		cin>>a>>b;
		v.push_back({a*b,{a,b}});
	}
	sort(v.begin(),v.end());
	dfs(v.size(),0);
	if(f==1) cout<<"YES\n";
	else cout<<"NO\n";
	//for(auto i:v) cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
}
