#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[100010],r[100010],res[100010];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i],res[i]=0;

	int ans=0;
	for(int i=29;i>=0;i--)
	{
		int f=1;
		for(int j=1;j<=n;j++)
		{
			int L=res[j]+(1<<i);
			int R=res[j]+(2<<i)-1;
			if(L>r[j]||R<l[j])
			{
				f=0;
				break;
			}
		}
		
		if(f) 
		{
			ans+=1<<i;
			for(int j=1;j<=n;j++) res[j]+=1<<i;
		}
		else
		{
			for(int j=1;j<=n;j++)
			{	
				int L=res[j]+(1<<i);
				int R=res[j]+(2<<i)-1;
				if(L<=r[j]&&R>=l[j])
				{
					if(L-1<l[j]) res[j]+=1<<i;
				}
			}
		}
	}
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
