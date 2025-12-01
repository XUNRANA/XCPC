#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<max({a*c,a*d,b*c,b*d})<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
