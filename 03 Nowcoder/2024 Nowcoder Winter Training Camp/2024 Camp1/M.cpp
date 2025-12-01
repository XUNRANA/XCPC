#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if(n%6==0) cout<<n/6<<"\n";
	else cout<<n/6*2<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
