#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	if(m<=r) cout<<"0 "<<m<<"\n";
	else cout<<-(m-r)<<" "<<r<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
