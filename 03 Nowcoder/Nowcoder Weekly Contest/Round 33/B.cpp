#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,x,k;
	cin>>n>>x>>k;
	cout<<n*x/k<<"\n";
	int s=0,cnt;
	for(int i=1;i<=n*x/k;i++)
	{
		cnt=0;
		while(s<k)
		{
			cnt++;
			s+=x;
		}
		s-=k;
		cout<<cnt<<" ";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

