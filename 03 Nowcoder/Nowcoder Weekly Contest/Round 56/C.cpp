#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int a;
	cin>>a;
	for(int i=1;i;i++)
	{
		if((a^i)<1||(a^i)>1e9) continue;
		cout<<i<<" "<<(a^i)<<"\n";
		return ;
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

