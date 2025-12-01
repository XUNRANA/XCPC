#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void solve() 
{
	int n=20;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++)
	{
		int a=rng()%1000;
		int b=rng()%1000;
		int c=rng()%1000;
		int d=rng()%1000;
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
