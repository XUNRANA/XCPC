#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
	cin>>n;
	if(n%2==0)
	{
		cout<<"YES\n";
		for(int i=1;i<=n/2;i++)
		{
			if(i&1) cout<<"AA";
			else cout<<"BB";
		}
		cout<<"\n";
	}
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
