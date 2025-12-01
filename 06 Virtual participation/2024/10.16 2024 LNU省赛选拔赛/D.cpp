#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,op,x,y;
	cin>>n;
	multiset<int>st;
	map<int,int>mp;
	while(n--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			if(st.count(x))
			{
				mp[x]+=y;
			}
			else
			{
				st.insert(x);
				if(y>1) mp[x]+=y-1;
			}
		}
		else if(op==2)
		{
			cin>>x>>y;
			if(!st.count(x)) continue;
			int t=mp[x]-y;
			if(t==0) mp.erase(x);
			else if(t<=-1) mp.erase(x),st.erase(x);
			else mp[x]=t;
		}
		else if(op==3)
		{
			mp.clear();
		}
		else
		{
			cin>>x;
			if(st.count(x))
			{
				int ans=1;
				if(mp.count(x)) ans+=mp[x];
				cout<<ans<<"\n";
			}
			else cout<<"0\n"; 
		}
	}
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
