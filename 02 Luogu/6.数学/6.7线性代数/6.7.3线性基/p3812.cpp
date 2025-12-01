#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[60],ans;
void insert(int x)
{
	for(int i=50;i>=0;i--)
	{
		if(x>>i&1)
		{
			if(p[i]) x^=p[i];
			else
			{
				p[i]=x;
				return ;
			}
		}
	}
}

void solve()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		insert(x);
	}
	for(int i=50;i>=0;i--) 
	{
		if((ans^p[i])>ans)
		ans^=p[i];
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
