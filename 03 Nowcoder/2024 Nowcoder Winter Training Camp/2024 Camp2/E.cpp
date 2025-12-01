#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[200010],ans;
void solve()
{
	ans=0;
	cin>>n;
	map<int,int>cnt;
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	set<int>s;
	for(int i=n;i>=1;i--)
	{
		s.insert(a[i]);
		cnt[a[i]]--;
		if(s.size()==cnt.size())
		{
			for(auto i:s) if(cnt[i]==0) cnt.erase(i);
			s.clear();
			ans++;
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
