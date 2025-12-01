#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int mx=-1,ans=0;
	for(int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		if(x>mx)
		{
			mx=x;
			ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
