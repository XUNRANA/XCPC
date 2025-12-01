#include <bits/stdc++.h>
using namespace std;
int n,k,ans,c,a[100010];
void solve()
{
	ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	if(a[i]>a[k])
	{
		if(i>k)
		{
			cout<<i-2<<"\n";
			return ;
		}
		else
		{
			ans=max(ans,i-2);
			c=0;
			if(i>=2) c++;
			for(int j=i+1;j<=k;j++)
			{
				if(a[j]<a[k]) c++;
				else
				{
					ans=max(ans,c);
					cout<<ans<<"\n";
					return ;
				}
			}
			
		}
	}
	cout<<n-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
