#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[2010];
void rever(int l,int r)
{
	while(l<r)
	{
		swap(a[l],a[r]);
		l++;
		r--;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int cur=n;
	vector<int>ans;
	while(1)
	{
		if(a[1]==cur) 
		{
			ans.push_back(cur);
			rever(1,cur);
			while(cur>=1&&a[cur]==cur) cur--;
			if(cur==0) break;
		}
		else
		{
			for(int i=1;i<=n;i++) 
			if(a[i]==cur)
			{
				ans.push_back(i);
				rever(1,i);
				break;
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
