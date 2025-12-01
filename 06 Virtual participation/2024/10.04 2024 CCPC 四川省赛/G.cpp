#include <bits/stdc++.h>
using namespace std;
int n,q,a,b,x[300010];
int fx(int x)
{
	return (a^x)-b;
}
int f(int x,int y)
{
	return fx(x)*fx(y);
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>x[i];
	while(q--)
	{
		cin>>a>>b;
		for(int i=1;i<n;i++)
		{
			cout<<" "<<f(x[i],x[i+1])<<"\n";
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
