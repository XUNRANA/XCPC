#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve()
{
	cin>>n>>k;
	if(n==k) 
	{
		while(n--) cout<<"1 ";
		cout<<"\n";
		return ;
	}
	
	if(k!=1) cout<<"-1\n";
	else 
	{
		for(int i=1;i<=n;i++) cout<<i<<" ";
		cout<<"\n";
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--) solve();
}
