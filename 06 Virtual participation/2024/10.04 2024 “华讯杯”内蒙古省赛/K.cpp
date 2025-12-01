#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010];
void work(int i,int j)
{
	while(i<j)
	{
		swap(a[i],a[j]);
		i++;
		j--;
	}
}
void solve()
{
	vector<pair<int,int>>ans;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==i)
				{
					work(i,j);
					ans.push_back({i,j});
					break;
				}
			}
		}
	}
	cout<<ans.size()<<"\n";
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
