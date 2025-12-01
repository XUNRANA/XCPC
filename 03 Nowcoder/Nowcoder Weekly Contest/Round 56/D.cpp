#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10010];
int ck(int a,int b,int c)
{
	if(b+c<=a) return 0;
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int f=0;
			for(int k=j+1;k<=n;k++)
			{
				if(ck(a[i],a[j],a[k]))
				{
					cout<<a[i]+a[j]+a[k]<<"\n";
					return ;
				}
				else 
				{
					f=1;
					break;
				}
			}
			if(f) break;
		}
	}
	cout<<"-1\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

