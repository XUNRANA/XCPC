#include <bits/stdc++.h>
using namespace std;
int a,b;
void solve()
{
	cin>>a>>b;
	cout<<max(a,b)<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t; 
	while(t--) solve();
}
