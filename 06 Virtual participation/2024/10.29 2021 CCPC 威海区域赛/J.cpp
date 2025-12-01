#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long a,b;
	cin>>a>>b;
	b=b*180;
	cout<<b/__gcd(a,b)-1<<"\n";
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
