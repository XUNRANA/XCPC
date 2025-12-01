#include <bits/stdc++.h>
using namespace std;

struct node
{
	int ip_cnt;
	vector<pair<int,string>>ip;
	string email;
}a1[10010];
bool cmp(node a1,node a2)
{
	if(a1.ip_cnt==a2.ip_cnt) return a1.email<a2.email;
	return a1.ip_cnt>a2.ip_cnt;
}
void solve()
{
	int n,a,b;
	cin>>n>>a>>b;
	map<string,map<string,int>>mp;
	for(int i=1;i<=n;i++)
	{
		string s,ip;
		cin>>s>>ip;
		mp[s][ip]++;
	}
	int idx=1;
	int mx=0;
	int f=0;
	for(auto i:mp)
	{
		int s=0;
		for(auto j:i.second) s+=j.second;
		mx=max(mx,(int)i.second.size());
		if(i.second.size()>a&&s>b)
		{
			f=1;
			a1[idx].ip_cnt=i.second.size();
			a1[idx].email=i.first;
			for(auto k:i.second) a1[idx].ip.push_back({-k.second,k.first});
			idx++;
		}
	}
	if(!f)
	{
		for(auto i:mp)
		{
			if(i.second.size()==mx)
			{
				a1[idx].ip_cnt=i.second.size();
    			a1[idx].email=i.first;
    			for(auto k:i.second) a1[idx].ip.push_back({-k.second,k.first});
    			idx++;
			}
		}
	}
	sort(a1+1,a1+idx,cmp);
	for(int i=1;i<idx;i++)
	{
		cout<<a1[i].email<<"\n";
		sort(a1[i].ip.begin(),a1[i].ip.end());
		for(auto j:a1[i].ip) cout<<j.second<<" "<<-j.first<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
