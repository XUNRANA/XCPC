#include <bits/stdc++.h>
using namespace std;
int n,k,a[100010];
void solve()
{
	cin>>n>>k;
	map<int,int>mp;
	vector<int>v;
	for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
	if(!k)
	{
		cout<<mp.size()<<"\n";
		return ;
	}
	for(auto i:mp) v.push_back(i.second);
	sort(v.begin(),v.end());
	vector<int>s(v.size(),0);
	s[0]=v[0];
	for(int i=1;i<v.size();i++) s[i]=s[i-1]+v[i];
	auto it=upper_bound(s.begin(),s.end(),k)-s.begin();
//	for(auto i:v) cout<<i<<" ";
//	cout<<"\n";
	if(it>=v.size()-1)
	{
		cout<<"1\n";
		return ;
	}
	cout<<v.size()-it<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
