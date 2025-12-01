#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,x;
	cin>>n>>x;
	if(x&1) cout<<n-x/2<<"\n";
	else cout<<n-x/2+1<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
