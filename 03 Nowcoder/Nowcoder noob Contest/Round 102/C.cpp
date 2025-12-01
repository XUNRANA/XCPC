#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,s,a[200010];
void solve()
{
	cin>>n>>sum;
	s=0;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];	
	if(s==sum)
	{
		cout<<"0\n";
		return ;
	}
	
	if(s>sum)
	{
		int k=s-sum,s1=0;
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=n;i++)
		{
			s1+=a[i]-(-10000);
			if(s1>=k)
			{
				cout<<i<<"\n";
				return ;
			}
		}
	}
	else
	{
		int k=sum-s,s1=0;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			s1+=10000-a[i];
			if(s1>=k)
			{
				cout<<i<<"\n";
				return ;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
