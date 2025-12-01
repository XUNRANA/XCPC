#include <bits/stdc++.h>
using namespace std;
#define int long long 
int k,n,ans,c,t1;
void solve()
{
	ans=1;
	c=0;
	cin>>n>>k;
	map<int,int>m;
	while(n--)
	{
		cin>>t1;
		if(t1%2==0) c++;
		m[t1%k]++;
	}
	
	if(m[0]>=1||(k==4&&c>=2)) cout<<"0\n";
	else 
	{ 
		ans=1e9;
		if(k==4&&m[1]>=1&&m[2]>=1) ans=min(ans,1ll);
		if(k==4&&m[1]>=2) ans=min(ans,2ll);
		for(int i=k-1;i>=1;i--)
		{
			if(m[i]>=1) ans=min(ans,k-i);
		}
		cout<<ans<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
