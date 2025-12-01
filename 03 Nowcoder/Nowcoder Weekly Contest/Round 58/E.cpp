#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,m;
	cin>>n>>m;
	if(m>3) cout<<"0\n";
	else if(n==1) cout<<n+1<<"\n";
	else if(n==2)
	{
		if(m==2) cout<<"2\n";
		else cout<<"3\n"; 
	}
	else
	{	
		if(m==1) cout<<n+1<<"\n";
		else if(m==2) cout<<n<<"\n";
		else cout<<"1\n";
	}
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

