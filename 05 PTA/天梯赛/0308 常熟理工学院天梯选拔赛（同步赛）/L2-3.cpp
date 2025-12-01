#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node
{
	int a,s,t;
}p[200010];

void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].s>>p[i].t;
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=1;j<i;j++)
		{
			if(p[j].s<p[i].s&&p[j].t>p[i].s&&p[j].a<=p[i].a)
			{
				ans=max(ans,p[i].a-p[j].a);
			}
		}
		cout<<ans<<" ";
	}
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

