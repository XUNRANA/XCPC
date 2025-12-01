#include <bits/stdc++.h>
using namespace std;
#define int long long 
int fx(int x)
{
	return sqrt(x);
}
void solve()
{
	int x;
	cin>>x;
	cout<<fx(x)<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
