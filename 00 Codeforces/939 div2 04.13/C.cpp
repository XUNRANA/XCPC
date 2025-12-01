#include <bits/stdc++.h>
using namespace std;
int n,s;
void solve()
{
	s=0;
	cin>>n;
	vector<int>a;
	vector<pair<int,int>>ans;
	for(int i=1;i<=n;i++) a.push_back(i);
	for(int i=1;i<=n;i++) s+=(2*i-1)*i;
	
	cout<<s<<" "<<2*n-1<<"\n";
	ans.push_back(make_pair(1,n));
	for(int i=n-1;i>=1;i--) 
	{
		ans.push_back(make_pair(2,i));
		ans.push_back(make_pair(1,i));
	}
	for(auto i:ans) 
	{
		cout<<i.first<<" "<<i.second<<" ";
		for(auto j:a) cout<<j<<" ";
		cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=0;
	cin>>t;
	while(t--) solve();
	
}
