#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int l,r;
	cin>>l>>r;
	if(r==1&&l==1) cout<<"1\n";
	else cout<<r-l<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
