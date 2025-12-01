#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<pair<int,int>>a(n);
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	for(int i=0;i;i++)
	{
		for(auto j:a) if(i%j.first==j.second)
		{
			cout<<i<<"\n";
			return ;
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--) solve();
}
