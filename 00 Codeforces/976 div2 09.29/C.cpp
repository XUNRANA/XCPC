#include <bits/stdc++.h>
using namespace std;
#define int long long
int b,c,d,ans;
void solve()
{
	cin>>b>>c>>d;
//	10 2^1
	ans=0;
	for(int i=0;i<=61;i++)
	{
		if(d>>i&1)
		{
			int b1=b>>i&1;
			int c1=c>>i&1;
			if(!b1&&c1)
			{
				cout<<"-1\n";
				return ;
			}
			if(b1&&c1) continue;
			ans+=(1ll<<i);
			 
			// 1 0    ->0/1
			// 1 1    ->0
			
			//0 0   ->1
			
		}
		else
		{
			int b1=b>>i&1;
			int c1=c>>i&1;
			if(b1&&!c1)
			{
				cout<<"-1\n";
				return ;
			}
			if(!b1&&!c1) continue;
			ans+=(1ll<<i);
		}
	}
	cout<<ans<<"\n";
//	a b c    d
//	0 0 0    0-0 =0
//	0 0 1    0-0 =0

//	0 1 0    1-0 =1
//	0 1 1    1-0 =1 

//	1 0 0    1-0 =1

//	1 0 1    1-1 =0 

//	1 1 0    1-0 =1

//	1 1 1    1-1 =0
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
