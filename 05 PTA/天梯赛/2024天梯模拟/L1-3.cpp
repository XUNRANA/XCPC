#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string x;
	int n,m,k;
	cin>>n>>x>>m>>k;
	if(k==n) cout<<"mei you mai "<<x<<" de";
	else if(k==m) cout<<"kan dao le mai "<<x<<" de";
	else cout<<"wang le zhao mai "<<x<<" de";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
