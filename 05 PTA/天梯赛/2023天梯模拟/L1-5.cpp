#include <bits/stdc++.h>
using namespace std;
int a[7];
void solve()
{
	for(int i=1;i<=6;i++) cin>>a[i];
	int n;
	cin>>n;
	for(int i=1;i<=6;i++)
	{
		int now=6-n+1;
		if(i!=1) cout<<" ";
		if(a[i]<now) cout<<now;
		else cout<<now-1;
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
