#include <bits/stdc++.h>
using namespace std;
#define int long long
int fi(int x,int n,int m)
{
	while(m&&x)
	{
		if(x==1) break;
		x=(x+1)/2;
		m--;
	}
	while(n&&x)
	{
		x/=2;
		n--;
	}
	return x;
}

int fx(int x,int n,int m)
{
	while(n&&x)
	{
		x/=2;
		n--;
	}
	while(m&&x)
	{
		if(x==1) break;
		x=(x+1)/2;
		m--;
	}
	return x;
}

void solve()
{
	int x,n,m;
	cin>>x>>n>>m;
	cout<<fi(x,n,m)<<" "<<fx(x,n,m)<<"\n";
}
  

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

