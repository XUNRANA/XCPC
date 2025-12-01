#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,ans;
void solve()
{
	ans=0;
	cin>>n;
	vector<int>j,o;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		if(t&1) j.push_back(t);
		else o.push_back(t);
	}
	sort(j.begin(),j.end());
	sort(o.begin(),o.end());
	if(!j.size()||!o.size()) cout<<"0\n";
	else 
	{
		t=j[j.size()-1];
		for(auto i:o)
		{
			if(t>i) t+=i;
			else 
			{
				cout<<o.size()+1<<"\n";
				return ;
			}
		}
		cout<<o.size()<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
