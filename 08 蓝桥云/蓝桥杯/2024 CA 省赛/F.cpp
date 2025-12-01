#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;	
			for(int k=1;k<=n;k++)
			{
				if(k==j||k==i) continue;
				for(int l=1;l<=n;l++)
				{
					if(l==k||l==j||l==i) continue;
					if(a[k]%a[i]==0&&a[l]%a[j]==0)
					{
						cout<<i<<" "<<j<<" "<<k<<" "<<l<<"\n";
					}
				} 
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
