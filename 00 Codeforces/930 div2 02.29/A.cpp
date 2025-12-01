#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
	cin>>n;
	for(int i=31;i>=0;i--) if(n>>i&1) 
	{
		cout<<(1<<i)<<"\n";
		return ;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
