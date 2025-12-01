#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x,y;
	cin>>x>>y;
	for(int i=0;i<=32;i++) 
	if((x>>i&1)!=(y>>i&1)) 
	{
		cout<<(1ll<<i)<<"\n";
		return ;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
