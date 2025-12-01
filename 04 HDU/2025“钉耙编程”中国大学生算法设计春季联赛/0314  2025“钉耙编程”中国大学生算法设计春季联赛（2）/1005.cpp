#include <bits/stdc++.h>
using namespace std;
#define int long long

int C(int x)
{
	return x/2*(x-x/2);
}
void solve()
{
	int n,k; 
	cin>>n>>k;
	if(k&1) cout<<"0\n";
	else
	{
		if(k==2)
		{
			cout<<n/2*(n-n/2)<<"\n";
		}
		else
		{
			int c=n/(k/2);
			int c0=n%(k/2);
			int c1=(k/2)-c0;
			cout<<c0*C(c+1)+c1*C(c)<<"\n";
		}
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

