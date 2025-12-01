#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x,n,ans=1;
	cin>>x>>n;
	vector<int>d;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0) 
		{
			d.push_back(i);
			if(x/i!=i) d.push_back(x/i);
		}
	}
	for(auto i:d) if(n<=i) ans=max(ans,x/i);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
