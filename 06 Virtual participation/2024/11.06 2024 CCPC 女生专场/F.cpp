#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007

int d[1000010];

void solve()
{
	
	for(int i=2;i<=1e6;i++)
	{
		if(!d[i])
		{
			for(int j=i;j<=1e6;j+=i) d[j]=i;
		}
	}
	int n;
	cin>>n;
	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		while(x>1)
		{
			int y=d[x];
			int c=0;
			while(x%y==0)
			{
				x/=y;
				c++;
			}
			mp[y].push_back(c);
		}
	}
	
	int ans=1;
	for(auto i:mp)
	{
		int x=i.first;
		int f0=1,f1=0;
		for(auto d:i.second)
		{
			int g0=0;
			int g1=0;
			int now=1;
			for(int j=0;j<=d;j++)
			{
				if(j&1)//奇数，加上贡献 
				{
					g0=(g0+f1*now%P*x%P)%P;
					g1=(g1+f0*now%P)%P;
					now=now*x%P;
				}
				else//偶数，直接+贡献 
				{
					g0=(g0+f0*now%P)%P;
					g1=(g1+f1*now%P)%P;
				}
//				cout<<j<<" "<<f0<<" "<<f1<<"\n";
//				cout<<j<<" "<<g0<<" "<<g1<<"\n";
			}
			f0=g0;
			f1=g1;
		}
		ans=ans*f0%P;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
