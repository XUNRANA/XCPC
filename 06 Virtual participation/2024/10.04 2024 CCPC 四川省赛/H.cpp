#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long n;
	cin>>n;
	if(n%3==0) cout<<1<<" "<<n/3<<"\n";
	else cout<<0<<" "<<n/3+n%3<<"\n"; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
