#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define N 200010
int n,a[N],b[N];
struct linear_basis
{
	int num[31];
	int rank;
	void clear()
	{
		rank=0;
		for(int i=0;i<31;i++) num[i]=0;
	}
	bool insert(int x)
	{
		for(int i=30;i>=0;i--)
		{
			if(x>>i&1)
			{
				if(num[i]==0)
				{
					num[i]=x;
					rank++;
					return true;
				}
				else x^=num[i];
			}
		}
		return false;
	}
}c[N];
int pw2[N];
void solve()
{
	cin>>n;
	for(int i=0;i<=n;i++) c[i].clear(),a[i]=b[i]=0;
	pw2[0]=1;
	for(int i=1;i<=n;i++)
	{
		pw2[i]=pw2[i-1]*2%P;
		int x;
		cin>>x;
		a[x]++;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			for(int j=0;j*i<=n;j++)
			{
				b[j*i]+=a[i];
				c[j*i].insert(i);
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<=n;i++) if(!i||a[i]) ans=(ans+pw2[b[i]-c[i].rank])%P;
	ans=(ans-1+P)%P;
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
