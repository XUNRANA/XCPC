#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
long long s;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	s=1500;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		if(s>=4000)
		{
			cout<<i<<"\n";
			return ;
		}
	}
	cout<<"-1\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
