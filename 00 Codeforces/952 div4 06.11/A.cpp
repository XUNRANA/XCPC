#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string a,b;
	cin>>a>>b;
	swap(a[0],b[0]);
	cout<<a<<" "<<b<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
