#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int n;
	cin>>n;
	if(n<=7) cout<<"-1\n";
	else
	{
		int i=n/2,j;
		if(i&1) j=i+1;
		else i++,j=i+1;
		for(int k=1;k<=n;k++)
		{
			if(k&1)
			{
				cout<<i<<" ";
				i+=2;
				if(i>n) i=1;
			}
			else
			{
				cout<<j<<" ";
				j+=2;
				if(j>n) j=2;
			}
		}
	} 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
