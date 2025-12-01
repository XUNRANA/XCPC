#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	while(k--)
	{
		n=(n+1)/2;
		if(n==1||n==0) break;
	}
	cout<<n<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
