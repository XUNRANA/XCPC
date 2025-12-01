#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	cout<<min(n,k)*min(m,k)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

