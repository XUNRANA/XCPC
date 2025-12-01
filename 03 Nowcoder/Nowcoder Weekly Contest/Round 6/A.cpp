#include <bits/stdc++.h>
using namespace std;
int a[10];
void solve()
{
	string s;
	cin>>s;
	int ans=0;
	for(auto i:s) ans+=a[i-'0'];
	cout<<ans<<"\n";
	
}
int main()
{
	a[0]=a[6]=a[9]=1;
	a[8]=2;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
