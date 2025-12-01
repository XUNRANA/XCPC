#include <bits/stdc++.h>
using namespace std;
int t,n,m;
void solve()
{
	cin>>n>>m;
	if(m%2==0) cout<<m*n/2<<"\n"; 
	else cout<<m/2*n<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
}
