#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,m,k;
	string x;
	cin>>n>>x>>m>>k;
	if(k==n) cout<<"mei you mai "<<x<<" de\n";
	else if(k==m) cout<<"kan dao le mai "<<x<<" de\n";
	else cout<<"wang le zhao mai "<<x<<" de\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

