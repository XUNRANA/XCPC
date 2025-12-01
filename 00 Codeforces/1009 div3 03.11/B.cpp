#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int ans=-(n-1);
	while(n--)
	{
		int x;
		cin>>x;
		ans+=x;
	}
	cout<<ans<<"\n";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

