#include <bits/stdc++.h>
using namespace std;
int n,a[2030],b[2030];
void solve()
{
	cin>>n;
	vector<pair<int,int>>ans;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			int f=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]>=a[j]&&a[j]>=b[i])
				{
					f=1;
					ans.push_back({i,j});
					swap(a[i],a[j]);
					break;
				}
			}
			if(!f)
			{
				cout<<"-1\n";
				return ;
			}
			else if(a[i]!=b[i]) i--;
		}
	}
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
