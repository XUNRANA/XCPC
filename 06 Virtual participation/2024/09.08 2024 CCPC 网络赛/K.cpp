#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve()
{
	cin>>n>>k;
	if((n&-n)<=k) cout<<"Alice\n";
	else cout<<"Bob\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
