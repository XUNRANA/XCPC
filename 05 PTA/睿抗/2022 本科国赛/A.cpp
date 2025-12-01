#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    
	vector<pair<int,int>>ans;
	int l=a[1]+15,r=l+30;
	int f=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=l&&a[i]<r) f=1;
		if(a[i]>=r+f*15)
		{
			ans.push_back({l,r+f*15-1});
			l=a[i]+15,r=a[i]+15+30;
			f=0;
		}
	}
	ans.push_back({l,r+f*15-1});
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
