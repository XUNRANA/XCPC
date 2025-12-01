#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) if(!(i&1)) cout<<i<<" ";
	for(int i=1;i<=n;i++) if(i&1) cout<<i<<" ";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

