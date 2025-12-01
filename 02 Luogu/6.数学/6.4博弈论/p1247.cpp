#include <bits/stdc++.h>
using namespace std;

int n,a[500010],ans;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ans^=a[i];
	}
	if(!ans) cout<<"lose\n";
	else
	{
		for(int i=1;i<=n;i++) 
		if(a[i]>(a[i]^ans))
		{
			cout<<a[i]-(a[i]^ans)<<" "<<i<<"\n";
			a[i]^=ans;
			break;
		}
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
