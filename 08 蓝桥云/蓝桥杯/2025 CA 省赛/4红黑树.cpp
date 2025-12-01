#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	int now=1;//RED
	while(k!=1)
	{
		if(k%2==0) now^=1;
		k=(k+1)/2;
	} 
	if(now) cout<<"RED\n";
	else cout<<"BLACK\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
