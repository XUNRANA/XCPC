#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	if(a==k||b==k||c==k) cout<<0<<"\n";
	else
	{
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		
		if(k>2) cout<<"-1\n";
		else if(k==2)
		{
			if(a==0&&b==1||a==0&&c==1) cout<<"1\n";
			else if(a==0||a==1) cout<<"2\n";
			else cout<<"3\n";
		}
		else if(k==1)
		{
			if(a==0) cout<<"1\n";
			else cout<<"2\n";
		}
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
