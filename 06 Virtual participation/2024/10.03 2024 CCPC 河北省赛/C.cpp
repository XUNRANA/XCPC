#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[1000010];
void solve()
{
	int n,l,r;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>l>>r;
		g[l].push_back({r,i});
	}
	int s=0;
	vector<int>ans;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int l=0;l<=n;l++)
	{
		if(l<=s) for(auto j:g[l]) q.push(j);
		
		while(!q.empty()&&q.top().first<s) q.pop();
		
		if(!q.empty())
		{
			int r=q.top().first;
			int idx=q.top().second;
			q.pop();
			s++;
			ans.push_back(idx);
		}
	}
	cout<<s<<"\n";
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
