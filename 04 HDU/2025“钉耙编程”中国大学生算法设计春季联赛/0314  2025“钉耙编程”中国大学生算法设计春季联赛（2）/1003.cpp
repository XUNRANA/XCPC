#include <bits/stdc++.h>
using namespace std;
#define int long long


int b[1000010];
int cnt[1000010];
void solve()
{
	int n,x;
	cin>>n;
	unordered_map<int,vector<int>>idx;
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		b[i]=x;
		idx[x].push_back(i);
	}
	unordered_set<int>st;
	for(int i=n;i>=1;i--)
	{
		if(b[i]) st.insert(b[i]);
		cnt[i]=st.size();
	}
	for(auto &i:idx) sort(i.second.begin(),i.second.end());	
	int ans=0;
	for(auto i:idx)
	{
		if(i.first==0) continue;
		int p=0;
		for(auto j:i.second)
		{
			if(p) 
			{
				auto it=lower_bound(idx[0].begin(),idx[0].end(),p);
				if(it!=idx[0].end()&&(*it<j))
				{
					ans+=cnt[j+1];
					break;
				}
				if(it==idx[0].end()) break;
			}
			p=j;
		}
	}
	cout<<ans<<"\n";
	
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

