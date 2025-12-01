#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,t;
void solve()
{
	cin>>n;
	map<int,int>m;
	for(int j=1;j<=n;j++)
	{
		cin>>t;
		for(int i=2;i*i<=t;i++)
		{
			while(t%i==0)
			{
				m[i]++;
				t/=i;
			}
		}
		if(t!=1) m[t]++;
	}
	for(auto i:m) 
	if(i.second%n!=0) 
	{
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
