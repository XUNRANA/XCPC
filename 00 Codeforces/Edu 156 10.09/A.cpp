#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if(n<=6) cout<<"NO\n";
	else
	{
		if(n==9) cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			if(n%3==0) cout<<"1 4 "<<n-1-4<<"\n";
			else if(n%3==1) cout<<"1 4 "<<n-1-4<<"\n";
			else cout<<"1 2 "<<n-1-2<<"\n";
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
