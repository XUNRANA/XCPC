#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int m,x;
	cin>>m>>x;
    if(x%m==0) cout<<m<<"\n";
	else cout<<x%m<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
