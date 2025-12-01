#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s="Scan the QR code to sign in now.";
	int ans=0;
	for(auto i:s) if(islower(i)) ans++;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
