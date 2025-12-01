#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long a,b,x;
	cin>>a>>b>>x;
	cout<<min({a*x,(x+2)/3*b,x/3*b+x%3*a});  
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
