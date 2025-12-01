#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k,d,w,s=0;
	cin>>n>>k;
	map<int,int>m;
	while(n--)
	{
		cin>>d>>w;
		m[d]+=w;
	}
	for(auto i:m)
	{
		s+=i.second;
		if(i.first*k<s)
		{
			cout<<"No\n";
			return ;
		}
	}
	cout<<"Yes\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
	cin>>T;
	while(T--) solve();
}
