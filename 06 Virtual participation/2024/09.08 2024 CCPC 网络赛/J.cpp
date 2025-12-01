#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 998244353
int n,ra,rb,a[1000010],b[1000010];
int num[31];
void insert(int x)
{
	for(int i=30;i>=0;i--)
	if(x>>i&1)
	{
		if(num[i]) x^=num[i];
	    else 
		{
			num[i]=x;
			return ;
		}
	}
}


void solve()
{
	cin>>n;
	for(int i=0;i<=30;i++) num[i]=0;
	ra=rb=0;
	for(int i=1;i<=n;i++) cin>>a[i],ra^=a[i];
	for(int i=1;i<=n;i++) cin>>b[i],rb^=b[i];
	for(int i=1;i<=n;i++) insert(a[i]^b[i]);
	
	for(int i=30;i>=0;i--)
	{
		int now=max(ra,rb);
		int res=max(ra^num[i],rb^num[i]);
		if(now>res)
		{
			ra^=num[i];
			rb^=num[i];
		}
	}
	cout<<max(ra,rb)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
