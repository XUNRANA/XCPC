#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,x,a[1010],ans[1010];
int is(int x)
{
	int t=sqrt(x);
	if(t*t==x) return 1;
	return 0;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(is(a[j]-a[i-1]))
			{
				ans[i]++;
				ans[j+1]--;
			}
		}
	}
	for(int i=1;i<=n;i++) ans[i]+=ans[i-1];
    while(q--)
	{
		cin>>x;
		cout<<ans[x]<<"\n";
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
