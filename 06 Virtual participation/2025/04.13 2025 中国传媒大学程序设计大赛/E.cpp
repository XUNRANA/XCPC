#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100010];
int f[100010];
void init()
{
	for(int i=2;i<=1e5;i++)
	{
		if(!f[i])
		{
			for(int j=i;j<=1e5;j+=i) if(!f[j]) f[j]=i;
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(__gcd(a[1],a[n])!=1)
	{
		cout<<"1\n1 "<<n<<"\n";
	}
	else
	{
		if(a[1]==1||a[n]==1) cout<<"-1\n";
		else
		{
			if(f[a[1]]*f[a[n]]<=n) 
			{
				int idx=0;
				for(int i=1;i<=n;i++) if(a[i]==f[a[1]]*f[a[n]]) idx=i;
				cout<<"2\n1 "<<idx<<" "<<n<<"\n";
			}
			else if(2*f[a[n]]<=n&&2*f[a[1]]<=n)
			{
				int idx1=0,idx2=0;
				for(int i=1;i<=n;i++) if(a[i]==2*f[a[1]]) idx1=i;
				else if(a[i]==2*f[a[n]]) idx2=i;
				cout<<"3\n1 "<<idx1<<" "<<idx2<<" "<<n<<"\n";
			}
			else cout<<"-1\n";
		}
	}
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}  
