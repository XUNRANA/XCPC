#include <bits/stdc++.h>
using namespace std;
long long t,n,k;
void solve()
{
	cin>>n>>k;
	while(n--)
	{
		for(int i=0;i<k;i++) cout<<char('a'+i);
	}
	cout<<"\n";
	
}
int main()
{
	cin>>t;
	while(t--) solve();
}
