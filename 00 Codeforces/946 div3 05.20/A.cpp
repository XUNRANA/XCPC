#include <bits/stdc++.h>
using namespace std;
int x,y,ans;
void solve()
{
	cin>>y>>x;
	ans=(x+1)/2;
	if(y>15*ans-x*4) ans+=(y-(15*ans-x*4)+14)/15;
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
