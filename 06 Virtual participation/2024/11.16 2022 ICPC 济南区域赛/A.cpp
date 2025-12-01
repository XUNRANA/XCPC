#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[510];
int cal(int x)
{
	vector<int>res;
	for(int i=1;i<=n;i++) 
	if(a[i]<=x) res.push_back(x-a[i]);
	else 
	{
		int t=a[i];
		int c=0,cnt=t-x;
		while(t>x)
		{
			t/=2;
			c++;
			cnt=min(cnt,c+abs(t-x));
		}
		res.push_back(cnt);
	}
	sort(res.begin(),res.end(),greater<int>());
	int ans=0;
	for(int i=m;i<res.size();i++) ans+=res[i];
	return ans;
}
void solve()
{
	cin>>n>>m;
	set<int>st;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		while(t)
		{
			st.insert(t);
			t/=2;
		}
	}
	int ans=1e9;
	for(auto i:st) ans=min(ans,cal(i));
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
