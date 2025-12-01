#include <bits/stdc++.h>
using namespace std;
int n,x,a[1010],b[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>x,b[x]=i;
	for(int i=1;i<=n;i++) a[i]=b[a[i]];
	string ans="";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				ans+='2';
			}
			else ans+='1';
		}
		ans+='1';
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
