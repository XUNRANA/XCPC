#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
void solve()
{
	int n;
	cin>>n;
	int c=n/2*2;
	int ans=(2+c)/2*(n/2)%P;
	cout<<ans<<"\n"; 
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

