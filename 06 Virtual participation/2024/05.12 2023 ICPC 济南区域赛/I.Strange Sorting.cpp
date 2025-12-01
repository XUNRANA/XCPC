#include <bits/stdc++.h>
using namespace std;
int n,a[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int j=n,i=1;
	vector<pair<int,int>>ans;
	while(j>=1)
	{
		while(j>=1&&a[j]==j) j--;
		for(int i=1;i<j;i++) 
		if(a[i]>a[j])
		{
			ans.push_back({i,j});
			sort(a+i,a+j+1);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans) cout<<i.first<<" "<<i.second<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
