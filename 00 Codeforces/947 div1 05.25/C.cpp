#include <bits/stdc++.h>
using namespace std;
int n,a[100010];

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2)
	{
		cout<<min(a[1],a[2])<<"\n";
		return ;
	}
	int ans=0;
	for(int i=3;i<=n;i++) 
	{
		vector<int>v;
		v.push_back(a[i-2]);
		v.push_back(a[i-1]);
		v.push_back(a[i]);
		sort(v.begin(),v.end());
		ans=max(ans,v[1]);
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
