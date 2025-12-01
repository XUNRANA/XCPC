#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string a,b;
	cin>>a>>b;
	for(int i=0;i<min(a.size(),b.size());i++)
	{
		if(a[i]<b[i])
		{
			cout<<a<<"<"<<b<<"\n";
			return ;
		}
		else if(a[i]>b[i])
		{
			cout<<a<<">"<<b<<"\n";
			return ;
		}
	}
	if(a.size()>b.size())
	{
		cout<<a<<">"<<b<<"\n";
		return ;
	}
	if(b.size()>a.size())
	{
		cout<<a<<"<"<<b<<"\n";
		return ;
	}
	cout<<a<<"="<<b<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
