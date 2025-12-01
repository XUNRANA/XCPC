#include <bits/stdc++.h>
using namespace std;
int x,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>x;
	while(x)
	{
		ans+=(x%2==1);
		x/=2;
	}
	cout<<ans<<"\n";
} 
