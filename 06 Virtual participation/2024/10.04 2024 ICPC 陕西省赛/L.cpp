#include <bits/stdc++.h>
using namespace std;
#define int long long 
int x;
void solve()
{
	cin>>x;
	for(int i=2;;i++)
	{
		if(x%i)
		{
			cout<<i<<"\n";
			return ;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
