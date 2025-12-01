#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c;
int ans[110];
void solve()
{
	cin>>a>>b>>c;
	cout<<100<<"\n";
	for(int i=1;i<=100;i++)
	{
		if(i<=50) cout<<a<<" ";
		else if(i<=95) cout<<b<<" ";
		else if(i<=99) cout<<c<<" ";
		else cout<<c+1<<" ";
	}
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
