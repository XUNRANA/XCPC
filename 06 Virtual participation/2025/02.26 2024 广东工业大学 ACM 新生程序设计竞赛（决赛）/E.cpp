#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) ans^=i;
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<(i+j-2)%n+1<<" ";
		}
		cout<<"\n";
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
