#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int n,p[N],fa[N];
vector<int>g[N];
int in[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) in[i]=0;
	for(int i=2;i<=n;i++) cin>>fa[i],in[fa[i]]++;
	
	vector<int>st;
	for(int i=2;i<=n;i++) if(!in[i]) st.push_back(i);
	
	int ans=n;
	int cnt=0;//²ãÊý 
	while(st.size())
	{
		int sz=st.size();
		ans=min(ans,cnt+sz);
		cnt++;
		vector<int>st1;
		for(auto i:st)
		{
			if(!fa[i]) continue;
			in[fa[i]]--;
			if(!in[fa[i]]) st1.push_back(fa[i]);
		}
		st=st1;
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
