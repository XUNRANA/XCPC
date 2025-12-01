#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if((a+b+c)&1) cout<<"-1\n";
	else cout<<min((a+b+c)/2,a+b)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
