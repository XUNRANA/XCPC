#include <bits/stdc++.h>
using namespace std;
long long n;
void solve()
{
	cin>>n;
	if(n&1)
	{
		for(int i=1;i<=n;i++) cout<<n<<" ";
		cout<<"\n";
	}
	else
	{
		for(int i=1;i<n;i++) cout<<"0 ";
		cout<<n<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
