#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[300010],x,s,s1;
void solve()
{
	cin>>n>>k;
	map<int,int>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		m[abs(x)]+=a[i];
	}
	s=s1=0;
	for(auto i:m)
	{	
		s+=k*i.first;
		if(s<i.second)
		{
			cout<<"NO\n";
			return ;
		}
		s1+=i.second;
		s=-s1;
	}
	cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
