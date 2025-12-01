#include <bits/stdc++.h>
using namespace std;
#define int long long
int k,z,b[100010],ans[100010],j,s;
void solve()
{
	cin>>k>>z;
	s+=z;
	for(int i=0;i<k;i++) cin>>b[i],s+=b[i];
	
	for(int i=k-1;i>=0;i--)
	{
		if(b[i]==1)
		{
			if(j%2==0) ans[i]=1;
			b[i]=0;
			j++;
		}
	}
	
	if(s&1)
	{
		for(int i=0;i<=k-1;i++)
		{
			if(b[i])
			{
				ans[i]=1;
			}
		}
	}	
	
	for(int i=k-1;i>=0;i--) cout<<ans[i];
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
